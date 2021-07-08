#ifndef WINDOWNEWPROJECT_H
#define WINDOWNEWPROJECT_H

#include <QDialog>
#include <QModelIndexList>

namespace Ui {
    class WindowNewProject;
}

struct NewProjectInfo
{
    QString type;
    QString name;
    QString description;
    bool(*createCb)(const QString& projPath, const QString& projName);
};

struct NewProjectResult
{
    bool isSuccess;
    QString projName;
    QString projPath;
    QString projFullPath;
};

class WindowNewProject : public QDialog
{
    Q_OBJECT

public:
    explicit WindowNewProject();
    ~WindowNewProject();
public:
    static void registerProjTemplate(const NewProjectInfo& info);
    static NewProjectResult newProject();

private:
    void clearList();
    void resetState();
private:
    Ui::WindowNewProject* ui;
    bool hasResult = false;

    QString projName;
    QString projPath;
    QString projFullPath;

public:
private slots:
    void on_submit_clicked();
    void on_listView_clicked(const QModelIndex &index);
};

#endif // WINDOWNEWPROJECT_H
