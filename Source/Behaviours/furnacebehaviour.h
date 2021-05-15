#ifndef FURNACEBEHAVIOUR_H
#define FURNACEBEHAVIOUR_H

#include "behaviour.h"

class FurnaceBehaviour : public Behaviour
{
public:
    FurnaceBehaviour();
    ReavenEngine::TileType getTileType() override { return ReavenEngine::FURNACE_TYPE; }
};
Q_DECLARE_METATYPE(FurnaceBehaviour)
#endif // FURNACEBEHAVIOUR_H

