#ifndef TEXTURE_H
#define TEXTURE_H

#include <QPixmap>
#include "Globals.h"

class Texture
{
public:
    Texture(){};
    Texture(const Texture& t);
    Texture(const Texture* t);
    Texture(const QString& textureLocation, QString key, ReavenEngine::Material material, ReavenEngine::TileSizeType sizeType, bool isAnimated);
    QPixmap& getFrame(int index = 0);
    QString& getKey() { return m_Key; }
    bool IsAnimated() const { return m_IsAnimated; }
    ReavenEngine::TileSizeType getSizeType() const { return m_SizeType; }

private:
    QString m_Key;
    ReavenEngine::Material m_Material;
    ReavenEngine::TileSizeType m_SizeType;
    bool m_IsAnimated;
    QPixmap m_Image;
    int m_FrameCount;
    QVector<QPixmap> m_Frames;

public:
    bool operator==(const Texture& t) const;
};

Q_DECLARE_METATYPE(Texture)

#endif // TEXTURE_H
