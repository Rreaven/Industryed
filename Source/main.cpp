#include "mainwindow.h"
#include "Managers/resourcemanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ResourceManager* p_ResourceManager = ResourceManager::getInstance();//init
    p_ResourceManager->loadTextures();
    p_ResourceManager->loadTiles();
    p_ResourceManager->loadItems();

    MainWindow w;
    w.show();
    return a.exec();
}
