#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <QVariantMap>
#include <Globals.h>

class Behaviour
{
public:
    Behaviour();

    virtual ReavenEngine::TileType getTileType() = 0;
};
Q_DECLARE_METATYPE(Behaviour)
#endif // BEHAVIOUR_H
