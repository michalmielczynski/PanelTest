#ifndef QGRAPHICSCHROMATICABERRATIONFILTER_H
#define QGRAPHICSCHROMATICABERRATIONFILTER_H

#include <QObject>
#include <QPixmap>

class QGraphicsChromaticAberrationFilter : public QObject
{
    Q_OBJECT
public:
    explicit QGraphicsChromaticAberrationFilter(QObject *parent = 0);
    QPixmap filter(QPixmap, int);

signals:

public slots:

};

#endif // QGRAPHICSCHROMATICABERRATIONFILTER_H
