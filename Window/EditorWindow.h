#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QString>
#include <QMainWindow>

class EditorWindow : public QMainWindow
{
    Q_OBJECT
public:
    EditorWindow() : QMainWindow(nullptr){}
public:
    virtual QString getWindowType() const = 0;
    virtual void onWindowSave() {}
    virtual bool onWindowClosing() { return true; }
    virtual void onWindowClosed() {}

    template<typename T>
    static inline QString nameOf() {
        return T::windowType();
    }
};

#endif // EDITORWINDOW_H
