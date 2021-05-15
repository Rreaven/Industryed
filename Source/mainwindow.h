#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGridLayout>

#include "renderwidget.h"

class GlobalResourceDisplayWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void keyPressEvent(QKeyEvent* key) override;
    void generateBasicWorld();
    void showInventory();

private:
    RenderWidget* m_RenderArea;
    GlobalResourceDisplayWidget* m_InventoryWidget;
    bool m_InventoryVisible;

};
#endif // MAINWINDOW_H
