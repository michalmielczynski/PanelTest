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


private:

    void setupGraphicsView();
    void setupDockImageProperties();
    void makeConnections();

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPixmap m_pixmap;
    QGraphicsPixmapItem *pixmapItemPointer;
    ImagePropertiesDockWidget *imagePropDockWidget;
    ImageEffectsDockWidget *imageEffDockWidget;
};

#endif // MAINWINDOW_H
