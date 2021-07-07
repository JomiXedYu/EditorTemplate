#include "AssetDataBase.h"

AssetDataBase::AssetDataBase()
{

}

ActionEvents<>& AssetDataBase::onRefresh()
{
    static Action<> event;
    return event;
}

void AssetDataBase::refresh()
{
    static_cast<Action<>&>(onRefresh()).Invoke();
}
