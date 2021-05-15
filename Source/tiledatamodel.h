#ifndef TILEDATAMODEL_H
#define TILEDATAMODEL_H

#include <QVariantMap>
#include "Globals.h"

QT_FORWARD_DECLARE_CLASS(Texture)

class TileDataModel
{
public:
    TileDataModel(){}
    TileDataModel(QString tag, QString visibleName, ReavenEngine::TileType type, ReavenEngine::TileSizeType sizeType, QVariantMap metadata, bool isBreakable, int blockHealth, Texture* texture, Texture* parentTexture = nullptr, ReavenEngine::ParentTextureActivation parentTextureActivation = ReavenEngine::ONSTART)
    {
        Tag = tag;
        VisibleName = visibleName;
        Type = type;
        SizeType = sizeType;
        IsBreakable = isBreakable;
        BlockHealth = blockHealth;
        BlockMetadata = metadata;
        TexturePtr = texture;
        ParentTexturePtr = parentTexture;
        ParentTextureActivation = parentTextureActivation;
    }

    QString Tag;
    QString VisibleName;
    ReavenEngine::TileType Type;
    ReavenEngine::TileSizeType SizeType;
    QVariantMap BlockMetadata;
    bool IsBreakable;
    int BlockHealth;
    Texture* TexturePtr;
    Texture* ParentTexturePtr;
    ReavenEngine::ParentTextureActivation ParentTextureActivation;
};

#endif // TILEDATAMODEL_H
