#ifndef QGRAPHICSREDUCENOISEFILTER_H
#define QGRAPHICSREDUCENOISEFILTER_H

#include <QObject>
#include <QPixmap>

class QGraphicsReduceNoiseFilter : public QObject
{
    Q_OBJECT
public:
    explicit QGraphicsReduceNoiseFilter(QObject *parent = 0);

    QPixmap filter(const QPixmap &pixmap, int size);
signals:

public slots:

};

#endif // QGRAPHICSREDUCENOISEFILTER_H
