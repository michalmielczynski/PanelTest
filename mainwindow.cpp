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

void MainWindow::on_actionLoad_triggered(){
    QString filename = QFileDialog::getOpenFileName(
	    this,
	    tr("Open Document"),
	    QDir::currentPath(),
	    tr("Image Files (*.jpg *.jpeg *.png);;All files (*.*)") );

    m_pixmap.load(filename);
    if(!m_pixmap.isNull()){
	m_pixmapItemPointer->setPixmap(m_pixmap);
	m_scene->update(m_pixmapItemPointer->boundingRect());
    }
}


void MainWindow::setupGraphicsView(){
    ui->setupUi(this);
    setCentralWidget(ui->graphicsView);

    QBrush a(QColor(0,0,0));
    ui->graphicsView->setBackgroundBrush(a);

    m_scene = new QGraphicsScene;
    ui->graphicsView->setScene(m_scene);

    m_pixmapItemPointer = new QGraphicsPixmapItem;
    m_pixmapItemPointer = m_scene->addPixmap(m_pixmap);
    ui->graphicsView->setScene(m_scene);

}

void MainWindow::setupDockImageProperties(){
    m_imagePropDockWidget = new ImagePropertiesDockWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea,m_imagePropDockWidget);

    m_imageEffDockWidget = new ImageEffectsDockWidget(m_pixmapItemPointer,this);
    addDockWidget(Qt::RightDockWidgetArea,m_imageEffDockWidget);
}

void MainWindow::makeConnections(){

}
