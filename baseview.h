#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <QGraphicsPixmapItem>

class BaseView : public QGraphicsPixmapItem
{
public:
    BaseView(QPixmap &pixmap);
    ~BaseView();

protected:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter * painter,
                       const QStyleOptionGraphicsItem * option,
                       QWidget * widget);
    virtual QPainterPath shape() const;

private:
    qreal m_width;
    qreal m_height;
};

#endif // BASEVIEW_H
