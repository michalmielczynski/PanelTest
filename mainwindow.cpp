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
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    setupGraphicsView();
    setupDockImageProperties();
    makeConnections();

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




    pixmap.load(filename);
    if(!pixmap.isNull()){

	pixmapItemPointer = new QGraphicsPixmapItem;
	scene->clear();
	pixmapItemPointer = scene->addPixmap(pixmap);
	ui->graphicsView->setScene(scene);


	//ui->graphicsView->fitInView(item,Qt::KeepAspectRatio);
    }
}

void MainWindow::blurImage(int blurRange){



    qDebug()<<blurRange;

    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect(this);
    effect->setBlurHints(QGraphicsBlurEffect::QualityHint);
    effect->setBlurRadius(blurRange);

    pixmapItemPointer->setGraphicsEffect(effect);
    scene->update(pixmapItemPointer->boundingRect());
}

void MainWindow::setupGraphicsView()
{
    ui->setupUi(this);
    setCentralWidget(ui->graphicsView);

    QBrush a(QColor(0,0,0));
    ui->graphicsView->setBackgroundBrush(a);

    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);

}

void MainWindow::setupDockImageProperties()
{
    imagePropDockWidget = new ImagePropertiesDockWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea,imagePropDockWidget);

    imageEffDockWidget = new ImageEffectsDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,imageEffDockWidget);
}

void MainWindow::makeConnections()
{
    connect(imageEffDockWidget,SIGNAL(blur(int)),this,SLOT(blurImage(int)));
}
