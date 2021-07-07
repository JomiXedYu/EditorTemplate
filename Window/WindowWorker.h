#ifndef WINDOWWORKER_H
#define WINDOWWORKER_H

#include <QMainWindow>
#include <DockManager.h>

#include <ProjectManager.h>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowWorker; }
QT_END_NAMESPACE

class WindowWorker : public QMainWindow
{
    Q_OBJECT

public:
    WindowWorker(QWidget *parent = nullptr);
    ~WindowWorker();
private slots:
    void on_action_file_new_project_triggered();
    void on_action_file_new_file_triggered();

private:
    Ui::WindowWorker *ui;
    ads::CDockManager* dockManager;
};
#endif // WINDOWWORKER_H
