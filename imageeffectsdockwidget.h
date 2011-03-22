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
    void blurImage(int blurRange);
    void bloomImage(int bloomRange, int opacityRange, int brightnessRange);


private slots:

    void on_blurOpacity_valueChanged(int );
    void on_blurBrightness_valueChanged(int );
    void on_blurRadius_valueChanged(int );


    void on_Blur_valueChanged(int );


private:
    Ui::ImageEffectsDockWidget *ui;
    QGraphicsPixmapItem *m_pGraphicsPixmapItem;

    int m_bloomBlurRadius;
    int m_bloomOpacity;
    int m_bloomBrightness;

};

#endif // IMAGEEFFECTSDOCKWIDGET_H
