#ifndef VIEWSCENE_H
#define VIEWSCENE_H

#include <QGraphicsScene>

class QGraphicsSceneMouseEvent;

class ViewScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit ViewScene(QObject *parent = 0);

};

#endif // VIEWSCENE_H
