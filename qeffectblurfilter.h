#ifndef QEFFECTBLURFILTER_H
#define QEFFECTBLURFILTER_H

#include <QObject>

class QEffectBlurFilter : public QObject
{
    Q_OBJECT
public:
    explicit QEffectBlurFilter(QObject *parent = 0);
    QPixmap filter(QPixmap,int);
signals:

public slots:

};

#endif // QEFFECTBLURFILTER_H
