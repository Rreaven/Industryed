#include "renderview.h"
#include "renderwidget.h"

#include <QWheelEvent>
#include <QPoint>
#include <QDebug>
#include <QScrollBar>


RenderView::RenderView(RenderWidget *v) : QGraphicsView(), m_RenderWidget(v)
{
    m_ScrollX = 0;
    m_ScrollY = 0;

    setRenderHint(QPainter::Antialiasing, true);
    setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setTransformationAnchor(QGraphicsView::AnchorViewCenter);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setInteractive(true);
}

void RenderView::wheelEvent(QWheelEvent *e)
{
    float delta = e->delta() / 120;
    m_RenderWidget->zoom(delta);
}


void RenderView::keyPressEvent(QKeyEvent *event)
{    
    if(event->key() == Qt::Key_A)
        m_ScrollX -= 5;
    else if(event->key() == Qt::Key_D)
        m_ScrollX += 5;
    else if(event->key() == Qt::Key_W)
        m_ScrollY -= 5;
    else if(event->key() == Qt::Key_S)
        m_ScrollY += 5;

    centerOn(m_ScrollX, m_ScrollY);

    m_RenderWidget->updateVisibleTiles();

    QGraphicsView::keyPressEvent(event);
}
