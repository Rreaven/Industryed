#include "renderscene.h"
#include "Globals.h"
#include "GUI/globalresourcedisplaywidget.h"
#include "Managers/resourcemanager.h"

#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsView>

RenderScene::RenderScene()
{
    m_GlobalInventory = GlobalResourceDisplayWidget::getInstance();
    m_ResourceManager = ResourceManager::getInstance();
    m_IsOccupied = false;
    m_IsMouseDown = false;

    m_GhostColorEffect = new QGraphicsColorizeEffect;

    m_GhostItem = new QGraphicsPixmapItem;
    m_GhostItem->setOpacity(0.6);
    m_GhostItem->setGraphicsEffect(m_GhostColorEffect);
}

void RenderScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton)
    {
        m_IsMouseDown = true;
        addItem(m_GhostItem);

        m_SelectedTile = m_GlobalInventory->getCurrentTile();
        m_GhostItem->setPixmap(m_SelectedTile.TexturePtr->getFrame());
        m_GhostItem->setPos(snapToGrid(mouseEvent->scenePos(), ReavenEngine::getProperTileSize(ReavenEngine::SMALL)));

        m_IsOccupied = checkSurroundings(mouseEvent->scenePos());
    }

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void RenderScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(m_IsMouseDown)
    {
        m_IsOccupied = checkSurroundings(mouseEvent->scenePos());
        if(m_IsOccupied)
            m_GhostColorEffect->setColor(Qt::red);
        else
            m_GhostColorEffect->setColor(Qt::green);

        m_GhostItem->setPos(snapToGrid(mouseEvent->scenePos(), ReavenEngine::getProperTileSize(ReavenEngine::SMALL)));
    }
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void RenderScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    removeItem(m_GhostItem);
    if((mouseEvent->button() == Qt::LeftButton) & !m_IsOccupied)
    {
        m_IsMouseDown = false;
        QPointF p = mouseEvent->scenePos();

        if(dynamic_cast<Tile*>(itemAt(p.x(), p.y(), QTransform()))->getTileType() != ReavenEngine::GROUND)
            return;

        int tileSize = ReavenEngine::getProperTileSize(ReavenEngine::SMALL);

        Tile* tile = new Tile(m_SelectedTile);
        tile->setPos(snapToGrid(p, tileSize));
        addItem(tile);
        update();
    }
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
QPoint RenderScene::snapToGrid(const QPointF &p, int tileSize)
{
    QPoint _p = p.toPoint();
    int mirroredX = 0;
    int mirroredY = 0;

    if(_p.x() < 0)
        mirroredX = tileSize;
    if(_p.y() < 0)
        mirroredY = tileSize;

    int snapX = (_p.x() / tileSize) * tileSize - mirroredX;
    int snapY = (_p.y() / tileSize) * tileSize - mirroredY;

    return QPoint(snapX, snapY);
}

bool RenderScene::checkSurroundings(const QPointF &p)
{
    int tileSize = ReavenEngine::getProperTileSize(m_SelectedTile.SizeType);
    QPoint snapP = snapToGrid(p, ReavenEngine::getProperTileSize(ReavenEngine::SMALL));
    auto neighbourItems = items(QRect(snapP.x(), snapP.y(), tileSize, tileSize));
    neighbourItems.removeOne(m_GhostItem);

    for(int i = 0; i < neighbourItems.count(); i++)
        if(dynamic_cast<Tile*>(neighbourItems[i])->getTileType() != ReavenEngine::GROUND)
            return true;

    return false;
}
