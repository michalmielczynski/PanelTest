#ifndef QGRAPHICSBLOOMEFFECT_H
#define QGRAPHICSBLOOMEFFECT_H

#include <QGraphicsEffect>
#include <QPainter>

class QGraphicsBloomFilter : public QGraphicsEffect
{
    Q_OBJECT
public:
    explicit QGraphicsBloomFilter(QObject *parent = 0);
    void setRadius(int radiusRange);
    void setOpacity(int opacityRange);
    void setBrightness(int brightnessRange);


protected:
    void draw(QPainter *painter);

signals:

private:
    int radius;
    int opacity;
    int brightness;

    QPixmap filter(const QPixmap &pixmap);
    QImage blurred(const QImage& image, const QRect& rect, int radius);
    QImage brightened(const QImage& image, int brightness);
    QImage composited(const QImage& img1, const QImage& img2, int opacity, QPainter::CompositionMode mode);
    QImage bloomed(const QImage& img, int blurRadius, int brightness, int opacity,QPainter::CompositionMode mode);

public slots:

};

#endif // QGRAPHICSBLOOMEFFECT_H
