#ifndef WINDOWPROJECT_H
#define WINDOWPROJECT_H

#include <QMainWindow>

#include "EditorWindow.h"

namespace Ui {
class WindowProject;
}

class WindowProject : public EditorWindow
{
    Q_OBJECT

public:
    WindowProject();
    ~WindowProject();

    static QString windowType();
public:

    QString getCurDir();

public:
    void onDataRefresh();

    virtual void showEvent(QShowEvent* e) override;
    virtual void closeEvent(QCloseEvent* e) override;
public:
    virtual QString getWindowType() const override;
    virtual void onWindowSave() override;
    virtual bool onWindowClosing() override;
    virtual void onWindowClosed() override;


private:
    Ui::WindowProject *ui;
};

#endif // WINDOWPROJECT_H
