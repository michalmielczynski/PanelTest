#include "qgraphicsreducenoisefilter.h"
#include <QPixmap>
#include <QImage>

QGraphicsReduceNoiseFilter::QGraphicsReduceNoiseFilter(QObject *parent) :
    QObject(parent)
{
}


QPixmap QGraphicsReduceNoiseFilter::filter(const QPixmap &pixmap){

    QImage img = pixmap.toImage();

    int ApetureMin = -(Size/2);
    int ApetureMax = (Size/2);



    return QPixmap::fromImage(step3);
}
