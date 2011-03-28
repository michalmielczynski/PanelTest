#ifndef QGRAPHICSSHARPENFILTER_H
#define QGRAPHICSSHARPENFILTER_H

#include <QObject>
#include <QPixmap>

class QGraphicsSharpenFilter : public QObject
{
    Q_OBJECT
public:
    explicit QGraphicsSharpenFilter(QObject *parent = 0);
    QPixmap filter(const QPixmap,int);

signals:

public slots:

};

#endif // QGRAPHICSSHARPENFILTER_H
