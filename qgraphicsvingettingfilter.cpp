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
    QImage temp = img;
    img.convertToFormat(QImage::Format_ARGB32_Premultiplied);
    float vignetScale = 0.01*size;

    const float invxRes = 1.f /img.width();
    const float invyRes = 1.f /img.height();


for(int x=0;x<=img.width();++x)
    for(int y=0;y<=img.height();++y)
    {
	const float nPx = x * invxRes;
	const float nPy = y * invyRes;
	const float xOffset = nPx - 0.5f;
	const float yOffset = nPy - 0.5f;
	const float tOffset = qSqrt(xOffset * xOffset + yOffset * yOffset);

const float invNtOffset = 1.f - (qFabs(tOffset) * 1.42f);
float vWeight = qMax(invNtOffset+vignetScale,0.f);
vWeight=qMin(vWeight,1.f);

QRgb pixel = img.pixel(x,y);

temp.setPixel(x,y,qRgb(qRed(pixel)*vWeight, qGreen(pixel)*vWeight, qBlue(pixel)*vWeight));
    }
//    QPainter painter(&img);
//    painter.setCompositionMode(QPainter::CompositionMode_Multiply);
//    painter.setOpacity(.7);
//    QRadialGradient gradient(img.width()/2,img.height()/2,img.width()/2+size);
//    gradient.setColorAt(0.0,Qt::white);
//    gradient.setColorAt(0.4,Qt::white);
//    gradient.setColorAt(1,Qt::black);
//    painter.setBrush(gradient);
//    painter.fillRect(img.rect(),gradient);
//    painter.drawImage(img.rect(),img);
//    painter.end();

    return pixmap.fromImage(temp);
}
