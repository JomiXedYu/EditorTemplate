#include <QApplication>
#include <QDir>
#include <QCoreApplication>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>

#include <Window/WindowWorker.h>
#include <Window/Dialog/WindowNewFile.h>
#include <Window/Dialog/WindowNewProject.h>
#include <ProjectManager.h>

static QJsonDocument parseJson(const QString& file)
{
    QFile qfile{ file };
    qfile.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument doc = QJsonDocument::fromJson(qfile.readAll());
    qfile.close();
    return doc;
}

void initNewFileType()
{
    QString curPath = QApplication::applicationDirPath();

    auto tmplPath = curPath + "/" + "FileTemplate";

    QJsonDocument doc = parseJson(tmplPath + "/index.json");

    auto arr = doc.array();
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        auto obj = (*it).toObject();
        WindowNewFile::registerFileType(
            {
                obj["type"].toString(),
                obj["name"].toString()
            }
        );
    }

    QDir dir{ tmplPath };
    dir.setFilter(QDir::Filter::Dirs | QDir::NoDotAndDotDot);

    for (auto& curfolder : dir.entryInfoList())
    {
        auto typeFolder = tmplPath + "/" + curfolder.fileName();

        auto doc = parseJson(typeFolder + "/index.json");
        auto arr = doc.array();

        for (const auto& jsitem : arr)
        {
            auto obj = jsitem.toObject();
            WindowNewFile::registerFileTemplate(
                curfolder.fileName(),
                {
                    obj["name"].toString(),
                    obj["desc"].toString(),
                    obj["file"].toString()
                }
            );
        }

    }
}
void initNewProject()
{
    WindowNewProject::registerProjTemplate({ "empty", "空项目", "创建一个空项目", nullptr });
}
void initAppStyle(QApplication& a)
{
    QFile qssFile(QDir::currentPath() + "/dark.qss");
    qssFile.open(QFile::ReadOnly);
    a.setStyleSheet(qssFile.readAll());
    qssFile.close();
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    initNewFileType();
    initNewProject();
    initAppStyle(a);

    WindowWorker::getInstance()->show();
    return a.exec();
}
