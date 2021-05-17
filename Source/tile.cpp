#include "tile.h"
#include "Managers/resourcemanager.h"
#include "Behaviours/furnacebehaviour.h"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QPainter>
#include <QKeyEvent>

Tile::Tile(const TileDataModel& dataModel)
{
    setAcceptHoverEvents(true);

    m_IsHover = false;
    m_DataModel = dataModel;
    m_Texture = m_DataModel.TexturePtr;
    m_TextureFrame = 0;
    m_ParentTextureFrame = 0;
    m_Rotation = 0;
    m_ParentTexture = dataModel.ParentTexturePtr;
    m_TileSize = ReavenEngine::getProperTileSize(m_DataModel.SizeType);

    switch(m_DataModel.Type)
    {
    case ReavenEngine::FURNACE_TYPE:
        m_TileBehaviour = new FurnaceBehaviour(this);
        break;
    default:
        m_TileBehaviour = nullptr;
    }

    setPixmap(m_Texture->getFrame());
}

void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->translate(m_TileSize / 2, m_TileSize/2);
    painter->rotate(m_Rotation);
    painter->translate(-m_TileSize / 2, -m_TileSize / 2);

    QGraphicsPixmapItem::paint(painter, option, widget);

    if(m_Texture->IsAnimated())
        m_Texture->getFrame(m_TextureFrame++);

    if(m_ParentTexture != nullptr)
    {
        if(m_ParentTexture->IsAnimated())
            painter->drawPixmap(QRect(3, 3, m_TileSize - 6, m_TileSize - 6), m_ParentTexture->getFrame(m_ParentTextureFrame++));
        else
            painter->drawPixmap(QRect(3, 3, m_TileSize - 6, m_TileSize - 6), m_ParentTexture->getFrame());
    }

    if(m_IsHover)
        painter->fillRect(QRect(0, 0, m_TileSize, m_TileSize), QColor(255, 255, 0, 100));
}

void Tile::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    m_IsHover = true;
    QGraphicsPixmapItem::hoverEnterEvent(event);
}

void Tile::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    m_IsHover = false;
    QGraphicsPixmapItem::hoverLeaveEvent(event);
}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::RightButton)
    {
        if(IsBreakable())
            scene()->removeItem(this);
    }
    if(event->button() == Qt::MouseButton::MiddleButton)
    {
        if(m_DataModel.Type != ReavenEngine::GROUND)
        {
            m_Rotation += 90;
            update();
        }
    }
}
