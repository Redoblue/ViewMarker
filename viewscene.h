#ifndef VIEWSCENE_H
#define VIEWSCENE_H

#include <QGraphicsScene>

class QGraphicsSceneMouseEvent;

class ViewScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit ViewScene(QObject *parent = 0);

signals:
    void mousePressed(QGraphicsSceneMouseEvent *);
    void mouseMoved(QGraphicsSceneMouseEvent *);
    void mouseReleased(QGraphicsSceneMouseEvent *);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
};

#endif // VIEWSCENE_H
