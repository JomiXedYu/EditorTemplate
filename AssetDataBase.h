#ifndef ASSETDATABASE_H
#define ASSETDATABASE_H

#include <Events.hpp>

class AssetDataBase
{
public:
    AssetDataBase();
public:
    static ActionEvents<>& onRefresh();

public:
    static void refresh();
};

#endif // ASSETDATABASE_H
