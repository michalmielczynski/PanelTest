#include "imageeffectsdockwidget.h"
#include "ui_imageeffectsdockwidget.h"
#include <QDebug>
#include <QGraphicsBlurEffect>

/**
  Class description:
  @todo
  - this class should have pointer to QPixmap from main class, initiated in constructor;
  - effects might be applied from GUI elements OR from mainwindow (calling same public methods declared in h file);

  /// @note
  - make sure main QPixmap is initiated before calling constructor here;
  - implement "effect stack" if possible, so effect might be applied "one over other";
  - do some efficiency tests for bigger images (check if OpenGL widgets would help);
  */

ImageEffectsDockWidget::ImageEffectsDockWidget(QGraphicsPixmapItem *p,QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ImageEffectsDockWidget)
{
    m_pGraphicsPixmapItem = p;
    ui->setupUi(this);
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setMinimumSize(200,200);
}

ImageEffectsDockWidget::~ImageEffectsDockWidget(){
    delete ui;
}

void ImageEffectsDockWidget::on_horizontalSlider_sliderMoved(int position){
    blurImage(position);
}

void ImageEffectsDockWidget::blurImage(int blurRange){

    qDebug()<<blurRange;

    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect(this);
    effect->setBlurHints(QGraphicsBlurEffect::QualityHint);
    effect->setBlurRadius(blurRange);
    m_pGraphicsPixmapItem->setGraphicsEffect(effect);
    /// @note prolem with scene
    //scene->update(pixmapItemPointer->boundingRect());
}


