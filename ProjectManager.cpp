#include "ProjectManager.h"

#include <QDir>
#include <QMessageBox>
#include <exception>
#include <QException>

ProjectManager::ProjectManager()
{

}

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
    return projectPath_ + "/Project";
}

QString ProjectManager::projectTemp()
{
    return projectPath_ + "/Temp";
}
/*
static QString* GetLastErrorHandle() {
    static QString qstr;
    return &qstr;
}
static void SetLastError(const QString& str)
{
    *GetLastErrorHandle() = str;
}
QString ProjectManager::GetLastError()
{
    return QString();
}
*/
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
    if (isOpened_) {
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

    ProjectInfo info;
    info.projectName = projectName_;
    info.projectPath = projectPath_;

    static_cast<Action<>&>(openProjectEvent()).Invoke();

    return true;
}

bool ProjectManager::newProject(const QString& folderPath)
{
    QDir dir(folderPath);
    if (dir.exists()) {
        QMessageBox::warning(nullptr, "alert", QObject::tr("文件夹存在"));
        return false;
    }
    dir.mkdir(folderPath);
    dir.mkdir("Project");
    dir.mkdir("Temp");
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
    if (!static_cast<Function<bool>&>(closingProjectEvent()).IsValidReturnInvoke()) {
        return false;
    }

    projectName_ = QString();
    projectPath_ = QString();
    isOpened_ = false;

    static_cast<Action<>&>(closedProjectEvent()).Invoke();
    return true;
}
