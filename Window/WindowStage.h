#ifndef WINDOWSTAGE_H
#define WINDOWSTAGE_H

#include <QMainWindow>
#include "EditorWindow.h"

namespace Ui {
class WindowStage;
}

class WindowStage : public EditorWindow
{
    Q_OBJECT
public:
    WindowStage();
    ~WindowStage();
    static QString windowType();
public:
    virtual QString getWindowType() const override;
private:
    Ui::WindowStage *ui;
};

#endif // WINDOWSTAGE_H
