#include "qgraphicsbloomfilter.h"
#include "qgraphicsblurfilter.h"
#include <QPainter>
#include <QPoint>
#include <QDebug>
#include <QRgb>

QGraphicsBloomFilter::QGraphicsBloomFilter(QObject *parent)
{
    blur = new QGraphicsBlurFilter(parent);
}


// Change brightness (positive integer) of each pixel
QImage QGraphicsBloomFilter::brightened(const QImage& image, int brightness){
    int tab[ 256 ];
    for (int i = 0; i < 256; ++i)
	tab[i] = qMin(i + brightness, 255);

    QImage img = image.convertToFormat(QImage::Format_ARGB32_Premultiplied);
    for (int y = 0; y < img.height(); y++) {
	QRgb* line = (QRgb*)(img.scanLine(y));
	for (int x = 0; x < img.width(); x++)
	    line[x] = qRgb(tab[qRed(line[x])], tab[qGreen(line[x])], tab[qBlue(line[x])]);
    }

    return img;
}

/// @todo check why with opacity == 0 is visible
// Composite two QImages using given composition mode and opacity
QImage QGraphicsBloomFilter::composited(const QImage& img1, const QImage& img2, int opacity, QPainter::CompositionMode mode){
    QImage result = img1.convertToFormat(QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&result);
    painter.setCompositionMode(mode);
    float op = (opacity / 256.0);
    painter.setOpacity(op);
    qDebug()<<"opacity"<<opacity;
    painter.drawImage(0, 0, img2);
    painter.end();
    return result;
}
/// @todo check why with opacity == 0 is visible
// Apply Bloom effect with the 4 parameters
QPixmap QGraphicsBloomFilter::filter(const QPixmap &pixmap, int blurRadius, int brightness, int opacity,QPainter::CompositionMode mode){

    qDebug()<<blurRadius<<brightness<<opacity;
    // (1) blur the original image

    QImage img= pixmap.toImage();
    QImage step1 = blur->filter(pixmap,blurRadius).toImage();


    // (2) increase the brightness of the blurred image
    QImage step2 = brightened(step1, brightness/5);

    // (3) finally overlay with the original image
    QImage step3 = composited(img, step2, opacity, mode);

    return QPixmap::fromImage(step3);
}
