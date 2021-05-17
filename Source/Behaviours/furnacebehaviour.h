#ifndef FURNACEBEHAVIOUR_H
#define FURNACEBEHAVIOUR_H

#include "behaviour.h"

class FurnaceBehaviour : public Behaviour
{
public:
    FurnaceBehaviour(){}
    FurnaceBehaviour(Tile* ownerTile);
    ReavenEngine::TileType getTileType() override { return ReavenEngine::FURNACE_TYPE; }
    QVector<Item> process() override;
};
Q_DECLARE_METATYPE(FurnaceBehaviour)
#endif // FURNACEBEHAVIOUR_H

