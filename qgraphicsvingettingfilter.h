#ifndef QGRAPHICSVINGETTINGFILTER_H
#define QGRAPHICSVINGETTINGFILTER_H

#include <QObject>
#include <QPixmap>

class QGraphicsVingettingFilter : public QObject
{
    Q_OBJECT
public:
    explicit QGraphicsVingettingFilter(QObject *parent = 0);
    QPixmap filter(QPixmap, int);

signals:

public slots:

};

#endif // QGRAPHICSVINGETTINGFILTER_H
