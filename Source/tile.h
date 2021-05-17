#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include <QVariantMap>

#include "texture.h"
#include "tiledatamodel.h"
#include "Behaviours/behaviour.h"

class  Tile : public QGraphicsPixmapItem
{
public:
    Tile(){}
    Tile(const TileDataModel& dataModel);
    ~Tile(){}

    bool IsBreakable() const { return m_DataModel.IsBreakable; }
    ReavenEngine::TileType getTileType() const { return m_DataModel.Type; }

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

private:
    Texture* m_Texture;
    Texture* m_ParentTexture;
    TileDataModel m_DataModel;
    uint m_TextureFrame;
    uint m_ParentTextureFrame;
    int m_TileSize;
    bool m_IsHover;
    short m_Rotation;
    Behaviour* m_TileBehaviour;
};

#endif // TILE_H
