#include "resourcemanager.h"

#include <QDir>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

ResourceManager* ResourceManager::instance = nullptr;
ResourceManager *ResourceManager::getInstance()
{
    if(instance == nullptr)
        instance = new ResourceManager();

    return instance;
}
TileDataModel& ResourceManager::getTileData(int index)
{
    return m_Tiles[index];
}

Item ResourceManager::getItem(int index)
{
    return m_Items[index];
}

QList<Item> ResourceManager::getItems()
{
    return  m_Items;
}

QList<TileDataModel> ResourceManager::getTiles()
{
    return m_Tiles;
}

ResourceManager::ResourceManager()
{
}

int ResourceManager::getTextureIndex(QJsonObject& obj, const QString &tag)
{
    QString textureLookup = obj.value(tag).toString();
    int textureIndex = 0;
    for(;textureIndex < m_Textures.count(); textureIndex++)
    {
        if(m_Textures[textureIndex]->getKey() == textureLookup)
            break;
    }

    return textureIndex;
}

void ResourceManager::loadTextures()
{
    QFile texturesJson(QApplication::applicationDirPath() + "/textures/info.json");
    if(!texturesJson.open(QFile::ReadOnly))
        return;

    QJsonDocument jsonResponse = QJsonDocument::fromJson(texturesJson.readAll());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["textures"].toArray();

    foreach (const QJsonValue& value, jsonArray)
    {
        QJsonObject obj = value.toObject();

        Texture* texture = new Texture(obj["fileName"].toString(),
                obj["id"].toString(),
                obj["material"].toVariant().value<ReavenEngine::Material>(),
                obj["sizeType"].toVariant().value<ReavenEngine::TileSizeType>(),
                obj["animated"].toBool());

        m_Textures.append(texture);
    }
}

void ResourceManager::loadTiles()
{
    QFile tilesJson(QApplication::applicationDirPath() + "/data/tiles.json");
    if(!tilesJson.open(QFile::ReadOnly))
        return;

    QJsonDocument jsonResponse = QJsonDocument::fromJson(tilesJson.readAll());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["tiles"].toArray();

    foreach (const QJsonValue& value, jsonArray)
    {
        QJsonObject obj = value.toObject();

        int textureIndex = getTextureIndex(obj, "textureLookup");

        TileDataModel tileData(obj["tag"].toString(),
                obj["name"].toString(),
                obj["type"].toVariant().value<ReavenEngine::TileType>(),
                m_Textures[textureIndex]->getSizeType(),
                obj["metadata"].toObject().toVariantMap(),
                obj["isBreakable"].toBool(),
                obj["blockHealth"].toInt(),
                m_Textures[textureIndex]);

        if(obj.contains("parentTexture") && obj.contains("parentTextureActivation"))
        {
            textureIndex = getTextureIndex(obj, "parentTexture");
            tileData.ParentTexturePtr = m_Textures[textureIndex];
            tileData.ParentTextureActivation = obj["parentTextureActivation"].toVariant().value<ReavenEngine::ParentTextureActivation>();
        }

        m_Tiles.append(tileData);
    }
}

void ResourceManager::loadItems()
{
    QFile tilesJson(QApplication::applicationDirPath() + "/data/items.json");
    if(!tilesJson.open(QFile::ReadOnly))
        return;

    QJsonDocument jsonResponse = QJsonDocument::fromJson(tilesJson.readAll());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["materials"].toArray();

    foreach (const QJsonValue& value, jsonArray)
    {
        QJsonObject obj = value.toObject();

        int textureIndex = getTextureIndex(obj, "textureLookup");

        Item item;
        item.Tag = obj["tag"].toString();
        item.VisibleName = obj["name"].toString();
        item.MaxStackSize = obj["maxStackSize"].toInt();
        item.Texture = m_Textures[textureIndex];
        item.MetaData = obj["itemMetadata"].toObject().toVariantMap();
        m_Items.append(item);
    }
}
