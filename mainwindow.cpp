/******************************************************************************
* Copyright 2010 by Klik Michal Mielczynski, 
* klik@klik.pl
* os. Przyjazni 7/25, 61-684 Poznan, Poland.
******************************************************************************/
/******************************************************************************
* Content of this file is copyrighted. Unauthorized use and distribution is not allowed.
* For licencing information, please contact us at klik@klik.pl
******************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->graphicsView);

    ImagePropDockWidget = new ImagePropertiesDockWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea,ImagePropDockWidget);

    ImageEffDockWidget = new ImageEffectsDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,ImageEffDockWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
