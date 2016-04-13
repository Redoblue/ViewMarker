#ifndef MARKERWIDGET_H
#define MARKERWIDGET_H

#include <QGraphicsView>
#include <memory.h>

class QString;
class QMouseEvent;
class QWheelEvent;
class QGraphicsSceneMouseEvent;
class ViewScene;
class BaseView;
class QGraphicsScene;

class MarkerWidget : public QGraphicsView
{
    Q_OBJECT

private:
    MarkerWidget(QWidget *parent = 0);

    bool isEmpty() const;

public:
    MarkerWidget(MarkerWidget const &) = delete;
    void operator =(MarkerWidget const &) = delete;
    static MarkerWidget *instance();

    void connectss();   //connect signals to slots
    //File menu
    void openFile(const QString &file);
    void closeFile();
    //View menu
    void fitToWindow();
    void zoomIn();
    void zoomOut();

protected:
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void wheelEvent(QWheelEvent *);

private:
    static MarkerWidget *_instance;
    QGraphicsScene *_pScene;
    BaseView *_pBaseView;

    qreal m_zoomInValue;
    qreal m_zoomOutValue;
    qreal m_zoomFactor;

    QString m_fileName;
    QPoint m_mousePos;
};

#endif // MARKERWIDGET_H
