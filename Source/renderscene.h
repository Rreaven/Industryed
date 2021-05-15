#ifndef RENDERSCENE_H
#define RENDERSCENE_H

#include <QGraphicsScene>
#include <QGraphicsColorizeEffect>

#include "tile.h"

QT_FORWARD_DECLARE_CLASS(ResourceManager)
QT_FORWARD_DECLARE_CLASS(GlobalResourceDisplayWidget)

class RenderScene : public QGraphicsScene
{
public:
    RenderScene();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    inline QPoint snapToGrid(const QPointF& p, int tileSize);
    inline bool checkSurroundings(const QPointF& p);

private:
    QGraphicsColorizeEffect* m_GhostColorEffect;
    TileDataModel m_SelectedTile;
    QGraphicsPixmapItem* m_GhostItem;
    ResourceManager* m_ResourceManager;
    GlobalResourceDisplayWidget* m_GlobalInventory;
    bool m_IsOccupied;
    bool m_IsMouseDown;

};

#endif // RENDERSCENE_H
