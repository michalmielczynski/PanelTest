#ifndef QGRAPHICSBLOOMEFFECT_H
#define QGRAPHICSBLOOMEFFECT_H

#include <QGraphicsEffect>
#include <QPainter>

class QGraphicsBloomEffect : public QGraphicsEffect
{
    Q_OBJECT
public:
    explicit QGraphicsBloomEffect(QObject *parent = 0);
    void setRadius(int radiusRange);


protected:
    void draw(QPainter *painter);

signals:

private:
    int radius;
    QImage blurred(const QImage& image, const QRect& rect, int radius);
    QImage brightened(const QImage& image, int brightness);
    QImage composited(const QImage& img1, const QImage& img2, int opacity, QPainter::CompositionMode mode);
    QImage bloomed(const QImage& img, int blurRadius, int brightness, int opacity,QPainter::CompositionMode mode);

public slots:

};

#endif // QGRAPHICSBLOOMEFFECT_H
