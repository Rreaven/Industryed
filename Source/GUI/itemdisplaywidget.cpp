#include "itemdisplaywidget.h"
#include "texture.h"
#include <QPainter>

ItemDisplayWidget::ItemDisplayWidget(TileDataModel &item, QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_TransparentForMouseEvents);
    m_TileData = item;
    m_Icon = item.TexturePtr->getFrame();
    m_Icon = m_Icon.scaled(32, 32);
}


void ItemDisplayWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter p(this);    
    p.drawPixmap(rect(), m_Icon);
}
