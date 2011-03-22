#include "imageeffectsdockwidget.h"
#include "ui_imageeffectsdockwidget.h"
#include "qgraphicsbloomeffect.h"
#include <QDebug>
#include <QGraphicsBlurEffect>

/**
  Class description:
  @todo
  - this class should have pointer to QPixmap from main class, initiated in constructor;
  - effects might be applied from GUI elements OR from mainwindow (calling same public methods declared in h file);
  - change QSliders to QSpinBox;
  - filters to implement
    - sharpen;
    - blur;
    - bloom/glow;
    - vignetting;
    - chromatic abberation;

  - implement "effect stack" if possible, so effect might be applied "one over other";
  - google out existing Qt based image filtering code, propose possible adaptations;

  /// @note
  - make sure main QPixmap is initiated before calling constructor here;
  - do some efficiency tests for bigger images (check if OpenGL widgets would help);
*/

ImageEffectsDockWidget::ImageEffectsDockWidget(QGraphicsPixmapItem *p, QWidget *parent) : /// @note always put one space after comma (, ) sign
    QDockWidget(parent),
    ui(new Ui::ImageEffectsDockWidget),
    m_pGraphicsPixmapItem(p),
    m_bloomBlurRadius(0),
    m_bloomOpacity(0),
    m_bloomBrightness(0)
{
    ui->setupUi(this);
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setMinimumSize(200,200);
}

ImageEffectsDockWidget::~ImageEffectsDockWidget(){
    delete ui;
}


void ImageEffectsDockWidget::blurImage(int blurRange){
    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect(this);
    effect->setBlurHints(QGraphicsBlurEffect::QualityHint);
    effect->setBlurRadius(blurRange);
    m_pGraphicsPixmapItem->setGraphicsEffect(effect);
}

void ImageEffectsDockWidget::bloomImage(int bloomRange, int opacityRange, int brightnessRange){

}


void ImageEffectsDockWidget::on_Blur_valueChanged(int position){
    blurImage(position);
}

void ImageEffectsDockWidget::on_blurRadius_valueChanged(int blurRadius){
    QGraphicsBloomEffect *effect = new QGraphicsBloomEffect(this);
    effect->setRadius(blurRadius);
    effect->setOpacity(m_bloomOpacity);
    effect->setBrightness(m_bloomBrightness);
    m_pGraphicsPixmapItem->setGraphicsEffect(effect);
    m_bloomBlurRadius=blurRadius;
}

void ImageEffectsDockWidget::on_blurBrightness_valueChanged(int brightnessRange ){
    QGraphicsBloomEffect *effect = new QGraphicsBloomEffect(this);
    effect->setOpacity(m_bloomOpacity);
    effect->setRadius(m_bloomBlurRadius);
    effect->setBrightness(brightnessRange);
    m_pGraphicsPixmapItem->setGraphicsEffect(effect);
     m_bloomBrightness=brightnessRange;
}

void ImageEffectsDockWidget::on_blurOpacity_valueChanged(int opacityRange){
    QGraphicsBloomEffect *effect = new QGraphicsBloomEffect(this);
    effect->setRadius(m_bloomBlurRadius);
    effect->setBrightness(m_bloomBrightness);
    effect->setOpacity(opacityRange);
    m_pGraphicsPixmapItem->setGraphicsEffect(effect);
     m_bloomOpacity=opacityRange;
}
