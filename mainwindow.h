/******************************************************************************
* Copyright 2010 by Klik Michal Mielczynski, 
* klik@klik.pl
* os. Przyjazni 7/25, 61-684 Poznan, Poland.
******************************************************************************/
/******************************************************************************
* Content of this file is copyrighted. Unauthorized use and distribution is not allowed.
* For licencing information, please contact us at klik@klik.pl
******************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imagepropertiesdockwidget.h"
#include "imageeffectsdockwidget.h"
#include <QGraphicsScene>
#include <QImage>

/**
  Target application:

  - main application's window contains QGraphicsView, that displays image;
  - image is loaded by user (from local jpg, png files) using dialog windows;
  - two dock widgets are available:
    - ImagePropertiesDockWidget;
    - ImageEffectsDockWidget;
  - both docks inherit from QDockWidget;
  - source code in english (class, methods, comments, output, etc.);
  - use of translate (tr) method for every output strings;

  // @todo add docks functionality

  */


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLoad_triggered();
    void blurImage(int blurRange);

private:

    void setupGraphicsView();
    void setupDockImageProperties();
    void makeConnections();

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPixmap pixMap;

    ImagePropertiesDockWidget *ImagePropDockWidget;
    ImageEffectsDockWidget *ImageEffDockWidget;
};

#endif // MAINWINDOW_H
