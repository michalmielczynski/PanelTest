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




    pixMap.load(filename);
    if(!pixMap.isNull()){

	QGraphicsPixmapItem *item= new QGraphicsPixmapItem;
	item->setPixmap(pixMap);

	scene->clear();
	scene->addItem(item);
	ui->graphicsView->setScene(scene);


	//ui->graphicsView->fitInView(item,Qt::KeepAspectRatio);
    }
}

void MainWindow::blurImage(int blurRange){

    qDebug()<<blurRange;

    QGraphicsPixmapItem *itemHelper;
    itemHelper->setPixmap(pixMap);
    QGraphicsBlurEffect effect;
    effect.setBlurHints(QGraphicsBlurEffect::QualityHint);
    effect.setBlurRadius(blurRange);

    itemHelper->setGraphicsEffect(&effect);
    scene->clear();


    scene->addItem(itemHelper);
    ui->graphicsView->setScene(scene);
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
    ImagePropDockWidget = new ImagePropertiesDockWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea,ImagePropDockWidget);

    ImageEffDockWidget = new ImageEffectsDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,ImageEffDockWidget);
}

void MainWindow::makeConnections()
{
    connect(ImageEffDockWidget,SIGNAL(blur(int)),this,SLOT(blurImage(int)));

}
