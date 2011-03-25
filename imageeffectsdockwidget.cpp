#include "imageeffectsdockwidget.h"
#include "ui_imageeffectsdockwidget.h"
#include "qgraphicsbloomfilter.h"
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
    m_effectNoiseReduction = new QGraphicsNoiseReductionFilter(this);
    ui->setupUi(this);
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setMinimumSize(200,200);
}

ImageEffectsDockWidget::~ImageEffectsDockWidget(){
    delete ui;
}


void ImageEffectsDockWidget::on_pushButtonBloom_clicked(){
    m_pGraphicsPixmapItem->setPixmap(m_effectBloom->filter(m_pGraphicsPixmapItem->pixmap(),ui->bloomRadius->value(),ui->bloomOpacity->value(),ui->bloomBrightness->value()));
}

void ImageEffectsDockWidget::on_pushButtonNoiseReduction_clicked(){
    m_pGraphicsPixmapItem->setPixmap(m_effectNoiseReduction->filter(m_pGraphicsPixmapItem->pixmap(),ui->spinBoxNoiseReduction->value()));
}
