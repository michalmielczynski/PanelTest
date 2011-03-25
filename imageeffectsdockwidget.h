#ifndef IMAGEEFFECTSDOCKWIDGET_H
#define IMAGEEFFECTSDOCKWIDGET_H

#include <QDockWidget>
#include <QGraphicsPixmapItem>
#include "qgraphicsbloomfilter.h"
#include "qgraphicsnoisereductionfilter.h"
#include "qgraphicsblurfilter.h"

namespace Ui {
    class ImageEffectsDockWidget;
}

class ImageEffectsDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit ImageEffectsDockWidget(QGraphicsPixmapItem *p, QWidget *parent = 0);
    ~ImageEffectsDockWidget();


private slots:

    void on_pushButtonBlur_clicked();
    void on_pushButtonNoiseReduction_clicked();
    void on_pushButtonBloom_clicked();


private:
    Ui::ImageEffectsDockWidget *ui;
    QGraphicsPixmapItem *m_pGraphicsPixmapItem;
    QGraphicsBloomFilter *m_filterBloom;
    QGraphicsNoiseReductionFilter *m_filterNoiseReduction;
    QGraphicsBlurFilter *m_filterBlur;


};

#endif // IMAGEEFFECTSDOCKWIDGET_H
