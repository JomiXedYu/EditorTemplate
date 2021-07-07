#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H
#include <QString>
#include <Events.hpp>

struct ProjectInfo
{
    QString projectName;
    QString projectPath;
};

class ProjectManager
{
private:
    static QString projectName_;
    static QString projectPath_;
    static bool isOpened_;
public:
    ProjectManager();
public:
    static bool isOpened();
    static QString projectName();
    static QString projectPath();
    static QString projectTemp();

    //static QString GetLastError();

    static ActionEvents<>& openProjectEvent();
    static FunctionEvents<bool>& closingProjectEvent();
    static ActionEvents<>& closedProjectEvent();
    static ActionEvents<>& saveEvent();

    //返回错误信息
    static bool openProject(const QString& folderPath);
    static bool newProject(const QString& folderPath);
    static bool newAndOpenProject(const QString& folderPath);
    static bool closeProject();
};

#endif // PROJECTMANAGER_H
