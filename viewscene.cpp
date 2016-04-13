#include "viewscene.h"

#include <QGraphicsSceneMouseEvent>

ViewScene::ViewScene(QObject *parent) : QGraphicsScene(parent)
{

}

void ViewScene::mousePressEvent(QGraphicsSceneMouseEvent *pEvent)
{
    emit mousePressed(pEvent);
}

void ViewScene::mouseMoveEvent(QGraphicsSceneMouseEvent *pEvent)
{
    emit mouseMoved(pEvent);
}

void ViewScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *pEvent)
{
    emit mouseReleased(pEvent);
}
