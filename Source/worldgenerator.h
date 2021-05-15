#ifndef WORLDGENERATOR_H
#define WORLDGENERATOR_H

#include <QList>

class WorldGenerator
{
public:
    WorldGenerator(int width, int height, int tileWidth, int tileHeight);

private:
    QVector<float> perlinNoise2D(int nWidth, int nHeight, int nOctaves, float fBias);



private:
    int m_Width;
    int m_Height;
    int m_TileWidth;
    int m_TileHeight;
};

#endif // WORLDGENERATOR_H
