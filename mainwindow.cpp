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
#include <QGraphicsPixmapItem>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->graphicsView);
    QBrush a(QColor(0,0,0));
    ui->graphicsView->setBackgroundBrush(a);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ImagePropDockWidget = new ImagePropertiesDockWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea,ImagePropDockWidget);

    ImageEffDockWidget = new ImageEffectsDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,ImageEffDockWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
	    this,
	    tr("Open Document"),
	    QDir::currentPath(),
	    tr("Image Files (*.jpg *.jpeg *.png);;All files (*.*)") );




    QPixmap pixMap(filename);
    if(!pixMap.isNull()){
	QGraphicsPixmapItem *image2= new QGraphicsPixmapItem;
	image2->setPixmap(pixMap);
	scene->clear();
	scene->addItem(image2);
	ui->graphicsView->setScene(scene);
	ui->graphicsView->fitInView(image2,Qt::KeepAspectRatio);
    }
}
