#include "ProjectManager.h"

#include <QDir>
#include <QMessageBox>
#include <QApplication>
#include <QStandardPaths>

#include <QFile>
#include <QTextStream>

QString ProjectManager::projectName_;
QString ProjectManager::projectPath_;
bool ProjectManager::isOpened_;

bool ProjectManager::isOpened()
{
    return isOpened_;
}

QString ProjectManager::projectName()
{
    return projectName_;
}

QString ProjectManager::projectPath()
{
    return projectPath_ + "/workspace";
}

QString ProjectManager::projectWorkspace()
{
    return QString();
}

QString ProjectManager::projectTemp()
{
    return projectPath_ + "/temp";
}

static QString _getRecentFilePath()
{
    return QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "/" + QApplication::applicationName() + "_recent.txt";
}

static QVector<QString>* _recentProjects()
{
    static QVector<QString>* p = nullptr;

    if (p == nullptr)
    {
        p = new QVector<QString>;

        QFile file{ _getRecentFilePath() };

        file.open(QIODevice::ReadWrite | QIODevice::Text);
        auto stream = QTextStream{ &file };
        while (!stream.atEnd())
        {
            auto line = stream.readLine();
            p->push_back(line);
        }

        file.close();
    }

    return p;
}

static void _addRecentProject(const QString& proj)
{
    if (_recentProjects() == nullptr)
    {
        return;
    }

    for (auto it = _recentProjects()->begin(); it != _recentProjects()->end(); it++)
    {
        if ((*it) == proj)
        {
            _recentProjects()->erase(it);
            break;
        }
    }
    
    int size = _recentProjects()->size();
    if (size >= 15)
    {
        for (int i = 0; i < size - 15; i++)
        {
            _recentProjects()->remove(0);
        }
    }
    _recentProjects()->push_back(proj);
}

static void _writeRecentProject()
{
    QFile file{ _getRecentFilePath() };
    if (file.exists()) {
        file.remove();
    }

    file.open(QIODevice::ReadWrite | QIODevice::Text);

    for (auto& item : *_recentProjects())
    {
        QTextStream{ &file } << item << endl;
    }

    file.close();
}

QVector<QString> ProjectManager::recentProjects()
{
    return QVector<QString>{ *_recentProjects() };
}

void ProjectManager::clearRecentProjects()
{
    _recentProjects()->clear();
    _writeRecentProject();
}

ActionEvents<>& ProjectManager::openProjectEvent()
{
    static Action<> event;
    return event;
}

FunctionEvents<bool>& ProjectManager::closingProjectEvent()
{
    static Function<bool> event;
    return event;
}

ActionEvents<>& ProjectManager::closedProjectEvent()
{
    static Action<> event;
    return event;
}

ActionEvents<>& ProjectManager::saveEvent()
{
    static Action<> event;
    return event;
}

bool ProjectManager::openProject(const QString& folderPath)
{
    if (isOpened_)
    {
        return false;
    }
    QDir dir(folderPath);
    if (!dir.exists()) {
        QMessageBox::warning(nullptr, "alert", QObject::tr("文件夹不存在"));
        return false;
    }
    projectName_ = dir.dirName();
    projectPath_ = folderPath;
    isOpened_ = true;

    _addRecentProject(folderPath);
    _writeRecentProject();

    static_cast<Action<>&>(openProjectEvent()).Invoke();

    return true;
}

static bool isFolderEmpty(const QString& folder)
{
    QDir dir{ folder };
    dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    return dir.entryInfoList().count() <= 0;
}

bool ProjectManager::newProject(const QString& folderPath)
{
    QDir dir(folderPath);
    if (dir.exists())
    {
        if (!isFolderEmpty(folderPath)) {
            QMessageBox::warning(nullptr, "alert", QObject::tr("文件夹存在"));
            return false;
        }
    }
    else
    {
        dir.mkdir(folderPath);
    }
    dir.mkdir(folderPath + "/workspace");
    dir.mkdir(folderPath + "/temp");
    return true;
}

bool ProjectManager::newAndOpenProject(const QString& folderPath)
{
    if (newProject(folderPath) && closeProject())
    {
        return openProject(folderPath);
    }
    return false;
}

bool ProjectManager::closeProject()
{
    if (!isOpened_)
    {
        return true;
    }
    if (!static_cast<Function<bool>&>(closingProjectEvent()).IsValidReturnInvoke()) {
        return false;
    }

    projectName_ = QString();
    projectPath_ = QString();
    isOpened_ = false;

    static_cast<Action<>&>(closedProjectEvent()).Invoke();
    return true;
}
