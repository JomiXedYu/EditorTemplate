#include <WindowManager.h>

struct WindowInfo
{
    std::function<EditorWindow* ()> creator;
    std::function<void(EditorWindow*)> deletor;
    bool isSingle;
};

static QMap<QString, WindowInfo>& getWindowInfos()
{
    static auto* map = new QMap<QString, WindowInfo>;
    return *map;
}
static QMap<QString, QList<EditorWindow*>>& getWindowList()
{
    static auto* list = new QMap<QString, QList<EditorWindow*>>;
    return *list;
}

void WindowManager::registerWindow(
    const QString& windowType,
    const bool& isSingle,
    const std::function<EditorWindow* ()>& creator,
    const std::function<void(EditorWindow*)>& deletor)
{

    getWindowInfos().insert(windowType, { creator, deletor, isSingle });
}

void WindowManager::unregisterWindow(const QString& windowType)
{
    auto it = getWindowInfos().find(windowType);
    if (it != getWindowInfos().end())
    {
        getWindowInfos().erase(it);
    }
}

EditorWindow* WindowManager::addWindow(const QString& windowType, const QString& title)
{
    auto& info = getWindowInfos()[windowType];
    auto& list = getWindowList()[windowType];

    if (info.isSingle && (list.size() != 0))
    {
        return nullptr;
    }

    return info.creator();
}

EditorWindow* WindowManager::getWindow(const QString& windowType)
{
    const auto& list = getWindowList()[windowType];
    if (list.size() != 0)
    {
        return list.last();
    }
    return nullptr;
}

QVector<EditorWindow*> WindowManager::getWindows(const QString& windowType)
{
    QVector<EditorWindow*> vec;
    const auto& list = getWindowList()[windowType];
    vec.reserve(list.size());

    for (auto& item : list)
    {
        vec.push_back(item);
    }
    return vec;
}

bool WindowManager::closeAllWindow()
{

    return false;
}

void WindowManager::saveAllWindow()
{

}
