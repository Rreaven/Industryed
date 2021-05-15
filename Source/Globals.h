#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtCore>

namespace ReavenEngine
{
    enum Material
    {
        NOTHING = 0,
        METAL = 1,
        SOIL = 2,
        WOOD = 3,
        GLASS = 4
    };

    enum TileType
    {
        GROUND = 0,
        DECORATION = 1,
        FURNACE_TYPE = 2,
        CRAFTER_TYPE = 3,
        DRILL_TYPE = 4,
        CONVEYOR_TYPE = 5,
        PIPE_TYPE = 6,
    };

    enum ParentTextureActivation
    {
        ONSTART = 0,
        ONREQUEST = 1,
    };
    enum TileSizeType
    {
        SMALL = 0,
        MEDIUM = 1,
        LARGE = 2,
        HUGE = 3
    };

    static inline int getProperTileSize(const TileSizeType& type)
    {
        switch (type)
        {
            case TileSizeType::SMALL:
            return 32;
            case TileSizeType::MEDIUM:
            return 64;
            case TileSizeType::LARGE:
            return 128;
            case TileSizeType::HUGE:
            return 256;

        }
    }
}
Q_DECLARE_METATYPE(ReavenEngine::Material)
Q_DECLARE_METATYPE(ReavenEngine::TileType)
Q_DECLARE_METATYPE(ReavenEngine::ParentTextureActivation)
Q_DECLARE_METATYPE(ReavenEngine::TileSizeType)
#endif // GLOBALS_H
