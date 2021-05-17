#include "furnacebehaviour.h"

FurnaceBehaviour::FurnaceBehaviour(Tile* ownerTile) : Behaviour(ownerTile)
{

}

QVector<Item> FurnaceBehaviour::process()
{

    //consume power
    //set animations
    return m_InputItems;
}
