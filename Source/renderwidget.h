#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTimer>
#include "renderscene.h"
#include "renderview.h"

class RenderWidget : public QWidget
{
public:
    RenderWidget();
    void zoom(float value);

    void setAreaSize(int width, int height);
    void addTile(QGraphicsItem* item);
    inline void updateVisibleTiles();
    void updateVisibleItemAnimations();

private:
    QGraphicsItemGroup *m_VisibleGroup;
    QTimer m_AnimationTimer;
    QVBoxLayout* m_MainLayout;

    QVector<QGraphicsItem*> m_VisibleItems;

    RenderScene* m_Scene;
    RenderView* m_View;

    float m_Zoom;
};

#endif // RENDERWIDGET_H
