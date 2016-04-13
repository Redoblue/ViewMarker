#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MarkerWidget;
class FileSystem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openFile();
    void closeFile();
    void switchFullScreen();
    void fitToWindow();
    void zoomIn();
    void zoomOut();
    void aboutApp();
    void aboutQt();

private:
    Ui::MainWindow *ui;

    MarkerWidget *_pMarkWidget;
    FileSystem *_pFileSystem;
};

#endif // MAINWINDOW_H
