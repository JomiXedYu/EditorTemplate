#ifndef WINDOWOUTLINER_H
#define WINDOWOUTLINER_H

#include <QMainWindow>
#include "EditorWindow.h"

namespace Ui {
class WindowOutliner;
}

class WindowOutliner : public EditorWindow
{
    Q_OBJECT

public:
    WindowOutliner();
    ~WindowOutliner();

    virtual QString getWindowType() const override;
    static QString windowType();

private:
    Ui::WindowOutliner *ui;
};

#endif // WINDOWOUTLINER_H
