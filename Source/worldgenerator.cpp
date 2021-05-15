#include "worldgenerator.h"
#include <QRandomGenerator64>

WorldGenerator::WorldGenerator(int width, int height, int tileWidth, int tileHeight)
{
    m_Width = width;
    m_Height = height;
    m_TileWidth = tileWidth;
    m_TileHeight = tileHeight;
}
//hiss
QVector<float> WorldGenerator::perlinNoise2D(int nWidth, int nHeight, int nOctaves, float fBias)
{
    QList<float> fSeed;

    for(int i = 0; i < nWidth * nHeight; i++)
        fSeed.append((float)QRandomGenerator64::global()->bounded(0, 100)/100);

    QList<float> fOutput;

    for(int y = 0; y < nHeight; y++)
    {
        for(int x = 0; x < nWidth; x++)
        {
            float fNoise = 0.0f;
            float fScale = 1.0f;
            float fScaleAcml = 0.0f;

            for (int o = 0; o < nOctaves; o++)
            {
                int nPitch = nWidth >> o;
                int nSampleX1 = (x / nPitch) * nPitch;
                int nSampleY1 = (y / nPitch) * nPitch;

                int nSampleX2 = (nSampleX1 + nPitch) % nWidth;
                int nSampleY2 = (nSampleY1 + nPitch) % nWidth;

                float fBlendX = (float)(x - nSampleX1) / (float)nPitch;
                float fBlendY = (float)(y - nSampleY1) / (float)nPitch;

                float fSampleT = (1.0f - fBlendX) * fSeed[nSampleY1 * nWidth + nSampleX1] + fBlendX * fSeed[nSampleY1 * nWidth + nSampleX2];
                float fSampleB = (1.0f - fBlendX) * fSeed[nSampleY2 * nWidth + nSampleX1] + fBlendX * fSeed[nSampleY2 * nWidth + nSampleX2];

                fNoise += (fBlendY * (fSampleB - fSampleT) + fSampleT) * fScale;
                fScaleAcml += fScale;
                fScale = fScale / fBias;
            }

            fOutput.append(fNoise / fScaleAcml);
        }
    }

    return fOutput.toVector();
}
