#ifndef RENDERVIEW_H
#define RENDERVIEW_H

#include <QGraphicsView>

class RenderWidget;

class RenderView : public QGraphicsView
{
    Q_OBJECT
public:
    RenderView(RenderWidget *v);

protected:
    void wheelEvent(QWheelEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    RenderWidget *m_RenderWidget;;
    float m_ScrollX;
    float m_ScrollY;
};
#endif // RENDERVIEW_H
