#include "mainwindow.h"
#include "Managers/resourcemanager.h"
#include "tile.h"
#include "Globals.h"
#include "GUI/globalresourcedisplaywidget.h"

#include <QDebug>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);

    m_InventoryVisible = false;

    QWidget* m_CentralWidget = new QWidget;
    setCentralWidget(m_CentralWidget);

    QGridLayout* m_MainLayout = new QGridLayout;
    m_MainLayout->setContentsMargins(0,0,0,0);
    m_CentralWidget->setLayout(m_MainLayout);

    m_InventoryWidget = GlobalResourceDisplayWidget::getInstance();
    m_InventoryWidget->setVisible(m_InventoryVisible);
    m_InventoryWidget->setFixedWidth(280);

    m_RenderArea = new RenderWidget;
    m_MainLayout->addWidget(m_RenderArea, 0, 0);
    m_MainLayout->addWidget(m_InventoryWidget, 0, 0, Qt::AlignRight);

    generateBasicWorld();
}

MainWindow::~MainWindow()
{
}

void MainWindow::keyPressEvent(QKeyEvent *key)
{
    if(key->key() == Qt::Key_Escape)
        close();
    else if(key->key() == Qt::Key_I)
        showInventory();
}

void MainWindow::generateBasicWorld()
{
    const int WORLDSIZE = 100;//get from user

    auto resourceManager = ResourceManager::getInstance();

    TileDataModel& tileData = resourceManager->getTileData(0);
    int tileSize = ReavenEngine::getProperTileSize(ReavenEngine::SMALL);

    m_RenderArea->setAreaSize(WORLDSIZE * tileSize, WORLDSIZE * tileSize);

    //100 x 32tiles
    for(int x = -WORLDSIZE; x <= WORLDSIZE; x++)
    {
        for(int y = -WORLDSIZE; y <= WORLDSIZE; y++)
        {
            Tile* grass = new Tile(tileData);
            grass->setPos(x * tileSize, y * tileSize);
            m_RenderArea->addTile(grass);
        }
    }
}

void MainWindow::showInventory()
{
    m_InventoryWidget->setHidden(m_InventoryVisible = !m_InventoryVisible);
}
