#include <QApplication>

#include "texture.h"
#include "Globals.h"

using namespace ReavenEngine;

Texture::Texture(const Texture &t)
{
    m_Key = t.m_Key;
    m_Material = t.m_Material;
    m_IsAnimated = t.m_IsAnimated;
    m_Image = t.m_Image;
}

Texture::Texture(const Texture *t)
{
    m_Key = t->m_Key;
    m_Material = t->m_Material;
    m_IsAnimated = t->m_IsAnimated;
    m_Image = t->m_Image;
}

Texture::Texture(const QString &textureLocation, QString key, ReavenEngine::Material material, ReavenEngine::TileSizeType sizeType, bool isAnimated)
{
    QPixmap img(QApplication::applicationDirPath() + "/textures/" + textureLocation);

    m_Key = key;
    m_Material = material;
    m_SizeType = sizeType;
    m_IsAnimated = isAnimated;
    m_FrameCount = 0;
    int tileSize = getProperTileSize(sizeType);
    m_Image = img.copy(QRect(0, 0, tileSize, tileSize));

    if(isAnimated)
    {
        int textureWidth = img.width();
        if(textureWidth % tileSize != 0)
            qDebug() << "texture width is not multiple of 32";
        m_FrameCount = img.width() / tileSize;
        for(int i = 0; i < m_FrameCount; i++)
            m_Frames.append(img.copy(tileSize * i, 0, tileSize, tileSize));
    }
}

QPixmap& Texture::getFrame(int index)
{
    if(m_IsAnimated)
        return m_Frames[index % m_FrameCount];

    return m_Image;
}

bool Texture::operator==(const Texture& t) const
{
    return (t.m_Key == m_Key);
}
