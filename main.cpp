#include <QApplication>
#include <QDir>
#include <QCoreApplication>
#include <QMessageBox>

#include <Window/WindowWorker.h>
#include <Window/Dialog/WindowNewFile.h>

#include <ProjectManager.h>

void Init()
{
    WindowNewFile::registerFileType({"plaintext", QObject::tr("纯文本 (.txt)"), QObject::tr("通用"), QObject::tr("创建空的纯文本文件"), QString("plaintext.txt"), QString(""), nullptr});
    WindowNewFile::registerFileType({"luascript", QObject::tr("Lua脚本 (.lua)"), QObject::tr("程序"), QObject::tr("创建空的Lua脚本文件"), QString("luascript.txt"), QString(""), nullptr});
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Init();

    QString projPath = QCoreApplication::applicationDirPath() + "/NewProject";
    ProjectManager::newProject(projPath);
    ProjectManager::openProject(projPath);

    QFile qssFile(QDir::currentPath() + "/dark.qss");
    qssFile.open(QFile::ReadOnly);
    a.setStyleSheet(qssFile.readAll());
    qssFile.close();

    WindowWorker w;
    w.show();
    return a.exec();
}
