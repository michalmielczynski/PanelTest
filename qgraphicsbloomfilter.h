#ifndef QGRAPHICSBLOOMEFFECT_H
#define QGRAPHICSBLOOMEFFECT_H

#include <QGraphicsEffect>
#include <QPainter>
#include <qgraphicsblurfilter.h>

class QGraphicsBloomFilter : public QObject
{
    Q_OBJECT
public:
    explicit QGraphicsBloomFilter(QObject *parent = 0);

    QPixmap filter(const QPixmap &pixmap, int, int, int,QPainter::CompositionMode mode);

protected:

signals:

private:
    QGraphicsBlurFilter *blur;
    QPixmap filter(const QPixmap &pixmap);
    QImage blurred(const QImage& image, const QRect& rect, int radius);
    QImage brightened(const QImage& image, int brightness);
    QImage composited(const QImage& img1, const QImage& img2, int opacity, QPainter::CompositionMode mode);
    QPixmap bloomed(const QImage& img, int blurRadius, int brightness, int opacity,QPainter::CompositionMode mode);

public slots:

};

#endif // QGRAPHICSBLOOMEFFECT_H
