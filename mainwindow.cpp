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
#include <QGraphicsBlurEffect>

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

	QGraphicsPixmapItem *item= new QGraphicsPixmapItem;
	item->setPixmap(pixMap);


	QGraphicsBlurEffect effect;
	effect.setBlurHints(QGraphicsBlurEffect::QualityHint);
	effect.setBlurRadius(5);

	item->setGraphicsEffect(&effect);
	scene->clear();
	scene->addItem(item);
	ui->graphicsView->setScene(scene);

//	item->pixmap().toImage().save("blur.png");
	//ui->graphicsView->fitInView(item,Qt::KeepAspectRatio);
    }
}

void MainWindow::blurImage()
{
//    QPixmap pixMap = scene->focusItem();
//    QGraphicsBlurEffect effect(this);
//    effect.
}
