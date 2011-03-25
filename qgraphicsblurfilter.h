#ifndef QGRAPHICSBLURFILTER_H
#define QGRAPHICSBLURFILTER_H

#include <QObject>
#include <QImage>
#include <QPixmap>

class QGraphicsBlurFilter : public QObject
{
    Q_OBJECT
public:
    explicit QGraphicsBlurFilter(QObject *parent = 0);
    QPixmap filter(QPixmap,int);
private:
    QImage blurred(const QImage& image, const QRect& rect, int radius);

signals:

public slots:

};

#endif // QGRAPHICSBLURFILTER_H
