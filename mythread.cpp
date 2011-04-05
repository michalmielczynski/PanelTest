#include "mythread.h"
#include <QtCore>
#include <QDebug>
#include <QPixmap>

MyThread::MyThread( QObject *parent,QGraphicsPixmapItem *pixmapItem):QThread(parent), m_pixmapItem(pixmapItem){

    m_pixmap = m_pixmapItem->pixmap();
    connect(this,SIGNAL(finished()),this,SLOT(setPixmap()));
}

void MyThread::setParameteres(int inSize){
    m_pixmap = (m_pixmapItem->pixmap());
    size = inSize;
}

 void MyThread::run(){
    qDebug()<<"running";
    m_pixmap = filter(m_pixmap,size);
}

void MyThread::setPixmap(){
    m_pixmapItem->setPixmap(m_pixmap);
    qDebug()<<"setting pixmap";
}


QPixmap MyThread::filter(QPixmap &inPixmap, int size){

   QImage img = inPixmap.toImage();
   QImage temp = img;
   size=100-size*5;

   for(int x=1; x<img.width()-1;x++){
       for(int y=1; y<img.height()-1; y++){
	   QColor p5(img.pixel(x,y));

	   QColor p1(img.pixel(x-1,y-1));
	   QColor p2(img.pixel(x,y-1));
	   QColor p3(img.pixel(x+1,y-1));
	   QColor p4(img.pixel(x-1,y));

	   QColor p6(img.pixel(x+1,y));
	   QColor p7(img.pixel(x-1,y+1));
	   QColor p8(img.pixel(x,y+1));
	   QColor p9(img.pixel(x+1,y+1));


	   int avgR = (p1.red() + p2.red() + p3.red() + p4.red()
		    + p6.red() + p7.red() + p8.red() + p9.red())/8;


	   int avgG = (p1.green() +p2.green() +p3.green() +p4.green() +p6.green()
		      +p7.green() +p8.green() +p9.green())/8;


	   int avgB = (p1.blue() + p2.blue() + p3.blue() + p4.blue()
		    + p6.blue() + p7.blue() + p8.blue() + p9.blue())/8;


	   int minMedianPointDiffR = qMax(avgR-size,0);
	   int maxMedianPointDiffR = qMin(avgR+size,255);

	   int minMedianPointDiffG = qMax(avgG-size,0);
	   int maxMedianPointDiffG = qMin(avgG+size,255);

	   int minMedianPointDiffB = qMax(avgB-size,0);
	   int maxMedianPointDiffB = qMin(avgB+size,255);



	    if( minMedianPointDiffR>p5.red() || maxMedianPointDiffR<p5.red() ||
		minMedianPointDiffG>p5.green() || maxMedianPointDiffG<p5.green() ||
		minMedianPointDiffB>p5.blue() || maxMedianPointDiffB<p5.blue()){
		    temp.setPixel(x,y,qRgb(avgR,avgG,avgB));
		}

       }

   }
   return inPixmap.fromImage(temp);

}
