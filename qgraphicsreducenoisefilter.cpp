#include "qgraphicsnoisereductionfilter.h"
#include <QPixmap>
#include <QImage>

QGraphicsReduceNoiseFilter::QGraphicsReduceNoiseFilter(QObject *parent) :
    QObject(parent)
{
}


QPixmap QGraphicsReduceNoiseFilter::filter(const QPixmap &pixmap, int size){

    QImage img = pixmap.toImage();
    int ApetureMin = -(size/2);
    int ApetureMax = (size/2);
    return QPixmap::fromImage(img);
}
