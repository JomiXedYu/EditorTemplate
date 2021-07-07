#ifndef WINDOWPROPERTYCONTROLS_H
#define WINDOWPROPERTYCONTROLS_H

#include <QMainWindow>
#include "EditorWindow.h"

namespace Ui {
class WindowPropertyControls;
}

class WindowPropertyControls : public EditorWindow
{
    Q_OBJECT

public:
    WindowPropertyControls();
    ~WindowPropertyControls();
    static QString windowType();
public:
    virtual QString getWindowType() const override;
private:
    Ui::WindowPropertyControls *ui;
};

#endif // WINDOWPROPERTYCONTROLS_H
