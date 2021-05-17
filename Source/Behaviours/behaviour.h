#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <QVariantMap>
#include <Globals.h>
#include <item.h>

QT_FORWARD_DECLARE_CLASS(Tile)

class Behaviour
{
public:
    Behaviour() {}
    Behaviour(Tile* ownerTile);

    virtual ReavenEngine::TileType getTileType() { return ReavenEngine::GROUND; }

    bool hasItemInputs() { return m_HasInputs; }
    void setInputItems(QVector<Item>& items) { m_InputItems = items; m_HasInputs = true; }

    bool hasItemOutputs() { return false; }
    void setOutputItems(QVector<Item>& items) { m_OutputItems = items; m_HasOutputs = true; }

    virtual QVector<Item> process() { return QVector<Item>(); }

protected:
    Tile* m_OwnerTile;

    bool m_HasInputs;
    bool m_HasOutputs;

    QVector<Item> m_InputItems;
    QVector<Item> m_OutputItems;
};
Q_DECLARE_METATYPE(Behaviour)
#endif // BEHAVIOUR_H
