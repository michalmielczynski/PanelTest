#ifndef QGRAPHICSNOISEREDUCTIONFILTER_H
#define QGRAPHICSNOISEREDUCTIONFILTER_H

#include <QObject>
#include <QPixmap>

class QGraphicsNoiseReductionFilter : public QObject
{
    Q_OBJECT
public:
    explicit QGraphicsNoiseReductionFilter(QObject *parent = 0);

    QPixmap filter(QPixmap, int);

signals:

public slots:

};

#endif // QGRAPHICSNOISEREDUCTIONFILTER_H
