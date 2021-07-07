#ifndef WINDOWNEWPROJECT_H
#define WINDOWNEWPROJECT_H

#include <QDialog>

namespace Ui {
class WindowNewProject;
}

class WindowNewProject : public QDialog
{
    Q_OBJECT

public:
    explicit WindowNewProject();
    ~WindowNewProject();

private:
    Ui::WindowNewProject *ui;
public:
    static QString newProject();
};

#endif // WINDOWNEWPROJECT_H
