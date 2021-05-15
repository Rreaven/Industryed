#ifndef GLOBALRESOURCEDISPLAYWIDGET_H
#define GLOBALRESOURCEDISPLAYWIDGET_H

#include <QListWidget>
#include "tiledatamodel.h"

QT_FORWARD_DECLARE_CLASS(ResourceManager)

class GlobalResourceDisplayWidget : public QListWidget
{
    Q_OBJECT
public:
    static GlobalResourceDisplayWidget* getInstance();
    TileDataModel& getCurrentTile() { return m_SelectedItem; }
private:
    static GlobalResourceDisplayWidget* instance;

    GlobalResourceDisplayWidget();
    GlobalResourceDisplayWidget(GlobalResourceDisplayWidget const&);
    void operator=(GlobalResourceDisplayWidget const&);


private:
    ResourceManager* m_ResourceManager;
    TileDataModel m_SelectedItem;

private slots:
    void updatedSelectedItem(int index);
};

#endif // GLOBALRESOURCEDISPLAYWIDGET_H
