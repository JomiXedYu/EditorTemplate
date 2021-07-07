#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H
#include <functional>
#include <QMap>

#include <Window/EditorWindow.h>
#include <Window/WindowWorker.h>

class WindowManager
{
public:
    static void registerWindow(
            const QString& windowType,
            const bool& isSingle,
            const std::function<EditorWindow*()>& creator,
            const std::function<void(EditorWindow*)>& deletor);
    static void unregisterWindow(const QString& windowType);

    static EditorWindow* addWindow(const QString& windowType, const QString& title);

    static EditorWindow* getWindow(const QString& windowType);
    static QVector<EditorWindow*> getWindows(const QString& windowType);


    static bool closeAllWindow();
    static void saveAllWindow();
};


#endif // WINDOWMANAGER_H
