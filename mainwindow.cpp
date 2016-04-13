#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "markerwidget.h"
#include "appproperties.h"
#include "filesystem.h"

#include <memory.h>
#include <QDebug>
#include <QMargins>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _pMarkWidget(MarkerWidget::instance()),
    _pFileSystem(new FileSystem)
{
    ui->setupUi(this);

    AppProrepties app;
    QCoreApplication::setApplicationName(app.name());
    QCoreApplication::setApplicationVersion(app.version());

    QMargins margins(0, 0, 0, 0);
    setContentsMargins(margins);

    setCentralWidget(_pMarkWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString file = _pFileSystem->openFile();
    _pMarkWidget->openFile(file);
}

void MainWindow::closeFile()
{
    _pMarkWidget->closeFile();
}

void MainWindow::switchFullScreen()
{
    if (!this->isFullScreen())
    {
        setWindowState(Qt::WindowFullScreen);
    }
    else
    {
        showNormal();
    }
}

void MainWindow::fitToWindow()
{
    _pMarkWidget->fitToWindow();
}

void MainWindow::zoomIn()
{
    _pMarkWidget->zoomIn();
}

void MainWindow::zoomOut()
{
    _pMarkWidget->zoomOut();
}

void MainWindow::aboutApp()
{
    qDebug() << "about app";
}

void MainWindow::aboutQt()
{
    qApp->aboutQt();
}
