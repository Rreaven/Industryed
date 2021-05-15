#include "renderwidget.h"
#include "tile.h"

#include <QtMath>
#include <QDebug>
#include <QGraphicsColorizeEffect>

RenderWidget::RenderWidget() : QWidget(nullptr)
{
    m_AnimationTimer.setInterval(250);
    connect(&m_AnimationTimer, &QTimer::timeout, this, &RenderWidget::updateVisibleItemAnimations);
    m_AnimationTimer.start();

    m_Zoom = 250.0f;
    m_Scene = new RenderScene;

    m_View = new RenderView(this);
    m_View->setBackgroundBrush(Qt::black);
    m_View->setScene(m_Scene);

    m_MainLayout = new QVBoxLayout;
    m_MainLayout->setContentsMargins(0, 0, 0, 0);
    m_MainLayout->addWidget(m_View);

    setLayout(m_MainLayout);
}


void RenderWidget::zoom(float value)
{
    m_Zoom += value * 5;
    if(m_Zoom >= 350)
        m_Zoom = 350;

    if(m_Zoom < 250)
        m_Zoom = 250;

    qreal scale = qPow(qreal(2), (m_Zoom - 250) / qreal(50));

    QMatrix matrix;
    matrix.scale(scale, scale);

    m_View->setMatrix(matrix);
    updateVisibleTiles();
}

void RenderWidget::setAreaSize(int width, int height)
{
    m_Scene->setSceneRect(-width / 2, -height / 2, width, height);

    m_View->centerOn(0, 0);
}

void RenderWidget::addTile(QGraphicsItem *item)
{
    m_Scene->addItem(item);
}

void RenderWidget::updateVisibleTiles()
{
    m_VisibleItems = m_Scene->items(m_View->mapToScene(m_View->viewport()->rect()), Qt::ItemSelectionMode::ContainsItemBoundingRect).toVector();
}

void RenderWidget::updateVisibleItemAnimations()
{
    for(int i = 0; i < m_VisibleItems.count(); i++)
    {
        Tile* tile = dynamic_cast<Tile*>(m_VisibleItems[i]);
        if(tile)
            tile->update();
    }
}
