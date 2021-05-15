#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "tiledatamodel.h"
#include "texture.h"
#include "item.h"
#include "Globals.h"

class ResourceManager
{
public:
    static ResourceManager* getInstance();
    TileDataModel& getTileData(int index);
    Item getItem(int index);
    QList<Item> getItems();
    QList<TileDataModel> getTiles();

private:
    static ResourceManager* instance;

    ResourceManager();
    ResourceManager(ResourceManager const&);
    void operator=(ResourceManager const&);

    int getTextureIndex(QJsonObject& obj, const QString& tag);

public:
    void loadTextures();
    void loadTiles();
    void loadItems();

private:
    QList<Texture*> m_Textures;
    QList<TileDataModel> m_Tiles;
    QList<Item> m_Items;
};

#endif // RESOURCEMANAGER_H

