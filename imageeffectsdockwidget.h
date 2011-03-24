#ifndef IMAGEEFFECTSDOCKWIDGET_H
#define IMAGEEFFECTSDOCKWIDGET_H

#include <QDockWidget>
#include <QGraphicsPixmapItem>
#include "qgraphicsbloomeffect.h"

namespace Ui {
    class ImageEffectsDockWidget;
}

class ImageEffectsDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit ImageEffectsDockWidget(QGraphicsPixmapItem *p, QWidget *parent = 0);
    ~ImageEffectsDockWidget();
    void bloomImage(int bloomRange, int opacityRange, int brightnessRange);


private slots:

    void on_bloomOpacity_valueChanged(int );
    void on_bloomBrightness_valueChanged(int );
    void on_bloomRadius_valueChanged(int );


    void on_Blur_valueChanged(int );


private:
    Ui::ImageEffectsDockWidget *ui;
    QGraphicsPixmapItem *m_pGraphicsPixmapItem;
    QGraphicsBloomFilter *m_effectBloom;


};

#endif // IMAGEEFFECTSDOCKWIDGET_H
