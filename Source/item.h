#ifndef ITEM_H
#define ITEM_H

#include <QVariantMap>

QT_FORWARD_DECLARE_CLASS(Texture)

class Item
{
public:
    Item(){}
    Item(const Item& item)
    {
        Tag = item.Tag;
        VisibleName = item.VisibleName;
        MaxStackSize = item.MaxStackSize;
        Texture = item.Texture;
        MetaData = item.MetaData;
    }

    QString Tag;
    QString VisibleName;
    int MaxStackSize;
    Texture* Texture;
    QVariantMap MetaData;
};

#endif // ITEM_H
