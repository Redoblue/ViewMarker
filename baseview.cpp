/******************************************************************
 * 在这个类里面进行质心的计算
 *
 * ****************************************************************/
#include "baseview.h"

#include <QGraphicsPixmapItem>
#include <QPainter>

BaseView::BaseView(QPixmap &pixmap)
{
    m_width = static_cast<qreal>(pixmap.width());
    m_height = static_cast<qreal>(pixmap.height());

    setPixmap(pixmap);
    setTransformationMode(Qt::SmoothTransformation);    //set transformation mode
    setShapeMode(QGraphicsPixmapItem::ShapeMode::BoundingRectShape);    //set shape mode, the fastest one
}

BaseView::~BaseView()
{

}

QRectF BaseView::boundingRect() const
{
    return QRectF(-pixmap().width() / 2,
                  -pixmap().height() / 2,
                  pixmap().width(), pixmap().height());
}

void BaseView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(-pixmap().width() / 2,
                        -pixmap().height() / 2, pixmap());
}

QPainterPath BaseView::shape() const
{
    QPainterPath path;
    path.addRect(QRectF(-pixmap().width() / 2,
                        -pixmap().height() / 2,
                        pixmap().width(), pixmap().height()));
    return path;
}
