#include "markerwidget.h"
#include "viewscene.h"
#include "baseview.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWheelEvent>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

MarkerWidget *MarkerWidget::_instance = nullptr;

MarkerWidget::MarkerWidget(QWidget *parent): QGraphicsView(parent),
    _pScene(new QGraphicsScene(this)),
    _pBaseView(nullptr),
    m_zoomInValue(0.8),
    m_zoomOutValue(1.25),
    m_zoomFactor(1.0)
{
    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheBackground);
    setTransformationAnchor(ViewportAnchor::AnchorUnderMouse);  //set transformation anchor to mouse pos
    setResizeAnchor(ViewportAnchor::AnchorUnderMouse);  //set resize anchor to mouse pos

    qreal view_width = static_cast<qreal>(width());
    qreal view_height = static_cast<qreal>(height());
    _pScene->setSceneRect(-view_width/2, -view_height/2,
                          view_width, view_height);
    setScene(_pScene);
    centerOn(0, 0);     //set view center to scene's

    //connectss();
}

MarkerWidget *MarkerWidget::instance()
{
    if (_instance == nullptr)
        _instance = new MarkerWidget;
    return _instance;
}

//void MarkerWidget::connectss()
//{
//    connect(_pScene, SIGNAL(mousePressed(QGraphicsSceneMouseEvent *)),
//            this, SLOT(onMousePressed(QGraphicsSceneMouseEvent *)));
//    connect(_pScene, SIGNAL(mouseMoved(QGraphicsSceneMouseEvent*)),
//            this, SLOT(onMouseMoved(QGraphicsSceneMouseEvent*)));
//    connect(_pScene, SIGNAL(mouseReleased(QGraphicsSceneMouseEvent*)),
//            this, SLOT(onMouseReleased(QGraphicsSceneMouseEvent*)));
//}

void MarkerWidget::openFile(const QString &file)
{
    QImage image;
    image.load(file);
    QPixmap pixmap = QPixmap::fromImage(image);
    _pBaseView = new BaseView(pixmap);
    _pScene->clear();
    _pScene->addItem(_pBaseView);
    _pBaseView->setPos(0, 0);

    fitToWindow();
}

void MarkerWidget::closeFile()
{
    _pScene->clear();
}

void MarkerWidget::fitToWindow()
{
    fitInView(_pBaseView, Qt::AspectRatioMode::KeepAspectRatio);
}

void MarkerWidget::zoomIn()
{
    scale(1.25, 1.25);
}

void MarkerWidget::zoomOut()
{
    scale(0.8, 0.8);
}

void MarkerWidget::mousePressEvent(QMouseEvent *pEvent)
{
    if (pEvent->button() == Qt::RightButton)
    {
        m_mousePos = pEvent->localPos().toPoint();
        setCursor(Qt::ClosedHandCursor);
    }
}

void MarkerWidget::mouseMoveEvent(QMouseEvent *pEvent)
{
    if (pEvent->button() == Qt::RightButton)
    {
        m_mousePos -= pEvent->localPos().toPoint();
        translate(m_mousePos.x(), m_mousePos.y());
        m_mousePos = pEvent->localPos().toPoint();
    }
}

void MarkerWidget::mouseReleaseEvent(QMouseEvent *pEvent)
{
    if (pEvent->button() == Qt::RightButton)
    {
        setCursor(Qt::ArrowCursor);
    }
}

void MarkerWidget::wheelEvent(QWheelEvent *pEvent)
{
    if(pEvent->delta() > 0)
        zoomIn();
    if(pEvent->delta() < 0)
        zoomOut();
}
