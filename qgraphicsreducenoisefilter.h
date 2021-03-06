#ifndef QGraphicsNoiseReductionFilter_H
#define QGraphicsNoiseReductionFilter_H

#include <QObject>
#include <QPixmap>

class QGraphicsNoiseReductionFilter : public QObject
{
    Q_OBJECT
public:
    explicit QGraphicsNoiseReductionFilter(QObject *parent = 0);

    QPixmap filter(const QPixmap &pixmap, int size);
signals:

public slots:

};

#endif // QGraphicsNoiseReductionFilter_H
