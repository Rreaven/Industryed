#ifndef ITEMDISPLAYWIDGET_H
#define ITEMDISPLAYWIDGET_H

#include <QWidget>

#include "tiledatamodel.h"
#include "item.h"

class ItemDisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ItemDisplayWidget(TileDataModel& item, QWidget *parent = nullptr);

    QSize sizeHint() const override { return QSize(32, 32); }

    TileDataModel& getSelectedTile() { return m_TileData; } ;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    TileDataModel m_TileData;
    QPixmap m_Icon;
};

#endif // ITEMDISPLAYWIDGET_H
