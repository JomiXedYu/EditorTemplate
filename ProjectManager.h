#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H
#include <QString>
#include <Events.hpp>

class ProjectManager
{
private:
    static QString projectName_;
    static QString projectPath_;
    static bool isOpened_;
public:
    ProjectManager() = delete;
public:
    static bool isOpened();
    static QString projectName();
    static QString projectPath();
    static QString projectWorkspace();
    static QString projectTemp();

    static QVector<QString> recentProjects();
    static void clearRecentProjects();

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
