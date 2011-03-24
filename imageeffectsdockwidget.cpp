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
    - bloom/glow;
    - chromatic abberation;
    - sharpen;
    - hot pixel;
    - ...
    - blur;
    - vignetting;

  - implement "effect stack" if possible, so effect might be applied "one over other";
  - google out existing Qt based image filtering code, propose possible adaptations;

  /// @note
  - do some efficiency tests for bigger images (check if OpenGL widgets would help);


  /// @todo
  Do NOT delete widget names in ui - for example ui->blurRadius should be renamed to spinBoxBlurRadius etc.
*/

ImageEffectsDockWidget::ImageEffectsDockWidget(QGraphicsPixmapItem *p, QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ImageEffectsDockWidget),
    m_pGraphicsPixmapItem(p)
{
    m_effectBloom = new QGraphicsBloomFilter(this);
    ui->setupUi(this);
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setMinimumSize(200,200);

}

ImageEffectsDockWidget::~ImageEffectsDockWidget(){
    delete ui;
}

void ImageEffectsDockWidget::on_Blur_valueChanged(int position){
    blurImage(position);

}


void ImageEffectsDockWidget::bloomImage(int bloomRange, int opacityRange, int brightnessRange){
   m_pGraphicsPixmapItem->setPixmap(m_effectBloom->filter(m_pGraphicsPixmapItem->pixmap(),bloomRange,opacityRange,brightnessRange));
  qDebug()<<"efekt";
}

void ImageEffectsDockWidget::on_bloomRadius_valueChanged(int blurRadius){
  bloomImage(blurRadius,ui->bloomOpacity->value(),ui->bloomBrightness->value());
}

void ImageEffectsDockWidget::on_bloomBrightness_valueChanged(int brightnessRange ){
    bloomImage(ui->bloomRadius->value(),ui->bloomRadius->value(),brightnessRange);
}

void ImageEffectsDockWidget::on_bloomOpacity_valueChanged(int opacityRange){
    bloomImage(ui->bloomRadius->value(),opacityRange,ui->bloomBrightness->value());
}
