#include "qgraphicsvingettingfilter.h"
#include "qmath.h"
#include <QDebug>
#include <QPainter>

QGraphicsVingettingFilter::QGraphicsVingettingFilter(QObject *parent) :
    QObject(parent)
{
}

QPixmap QGraphicsVingettingFilter::filter(QPixmap pixmap, int size)
{
    QImage img = pixmap.toImage();
    img.convertToFormat(QImage::Format_ARGB32_Premultiplied);


    QPainter painter(&img);
    painter.setCompositionMode(QPainter::CompositionMode_Multiply);
    painter.setOpacity(.7);


    QRadialGradient gradient(img.width()/2,img.height()/2,img.width()/2+size);
    gradient.setColorAt(0.0,Qt::white);
    gradient.setColorAt(0.4,Qt::white);
    gradient.setColorAt(1,Qt::black);


    painter.setBrush(gradient);
    painter.fillRect(img.rect(),gradient);
    painter.drawImage(img.rect(),img);
    painter.end();


//    int x0=img.width()/2 ;
//    int y0=img.height()/2;

//    int sizeX = x0-50;
//    int sizeY = y0-50;

//    for(int i=0;i<=10;i++)
//    {
//	for(int z=0;z<=50;z++)
//	{
//	    int x = x0 + (sizeX+z)*qSin(i);
//	    int y = y0 + (sizeY+z)*qCos(i);
//	    qDebug()<<x<<y;
//	    QRgb pixel = img.pixel(x,y);

//	    int r = qMax(qRed(pixel)-10,0);
//	    int g = qMax(qGreen(pixel)-10,0);
//	    int b = qMax(qBlue(pixel)-10,0);

//	    img.setPixel(x,y,qRgb(r,g,b));
//	}
//    }

    return pixmap.fromImage(img);
}
