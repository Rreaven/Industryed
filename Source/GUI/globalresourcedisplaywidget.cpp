#include "globalresourcedisplaywidget.h"
#include "Managers/resourcemanager.h"
#include "itemdisplaywidget.h"
#include "flowlayout.h"

#include <QGridLayout>
#include <QLabel>
#include <QPainter>
#include <QListWidgetItem>

GlobalResourceDisplayWidget* GlobalResourceDisplayWidget::instance = nullptr;
GlobalResourceDisplayWidget *GlobalResourceDisplayWidget::getInstance()
{
    if(instance == nullptr)
        instance = new GlobalResourceDisplayWidget;

    return instance;
}

GlobalResourceDisplayWidget::GlobalResourceDisplayWidget() : QListWidget(nullptr)
{
    setFocusPolicy(Qt::FocusPolicy::NoFocus);
    setAutoFillBackground(false);
    setStyleSheet("QListWidget{background-color: #abababab;} QListWidget::item { background : rgb(200,200,200); } QListWidget::item:selected { background: rgb(40,40,40); }");
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWrapping(true);
    setUniformItemSizes(true);
    setSpacing(3);
    setFlow(QListView::LeftToRight);
    setResizeMode(QListView::Adjust);

    m_ResourceManager = ResourceManager::getInstance();

    QList<TileDataModel> tiles = m_ResourceManager->getTiles();
    for(int i = 0; i < tiles.count(); i++)
    {
        ItemDisplayWidget* m_Idw = new ItemDisplayWidget(tiles[i]);
        QListWidgetItem* lwi = new QListWidgetItem;
        lwi->setSizeHint(m_Idw->sizeHint());
        addItem(lwi);
        setItemWidget(lwi, m_Idw);
    }
    connect(this, &QListWidget::currentRowChanged, this, &GlobalResourceDisplayWidget::updatedSelectedItem);
    setCurrentRow(tiles.count() - 1);
}

void GlobalResourceDisplayWidget::updatedSelectedItem(int index)
{
    m_SelectedItem = dynamic_cast<ItemDisplayWidget*>(itemWidget(currentItem()))->getSelectedTile();
}
