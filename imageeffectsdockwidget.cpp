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
    /// @note applying bloom maked image darker. Wrong composing mode?
    - bloom/glow;
    - chromatic abberation;
    - sharpen; ~ok
    - hot pixel; ok
    - ...
    - blur; ok
    - vignetting; ~ok

  - implement "effect stack" if possible, so effect might be applied "one over other";
  - google out existing Qt based image filtering code, propose possible adaptations;

  /// @note
  - do some efficiency tests for bigger images (check if OpenGL widgets would help);


  /// @todo
  Do NOT delete widget names in ui - for example ui->blurRadius should be renamed to spinBoxBlurRadius etc.
*/

ImageEffectsDockWidget::ImageEffectsDockWidget(QGraphicsPixmapItem *p, QPixmap *basePixmap, QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ImageEffectsDockWidget),
    m_pGraphicsPixmapItem(p),
    m_basePixmap(basePixmap)

{

    m_filterBloom = new QGraphicsBloomFilter(this);
    m_filterNoiseReduction = new QGraphicsNoiseReductionFilter(this);
    m_filterBlur = new QGraphicsBlurFilter(this);
    m_filterVingetting = new QGraphicsVingettingFilter(this);
    m_filterSharpen = new QGraphicsSharpenFilter(this);
    m_thread = new MyThread(this,m_pGraphicsPixmapItem);




    ui->setupUi(this);
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setMinimumSize(200,200);

    ui->comboBoxBloom->setEditable(false);
    ui->comboBoxBloom->addItem("Add");
    ui->comboBoxBloom->addItem("Multiply");
    ui->comboBoxBloom->addItem("Screen");
    ui->comboBoxBloom->addItem("Overlay");
    ui->comboBoxBloom->addItem("Darken");
    ui->comboBoxBloom->addItem("Lighten");
    ui->comboBoxBloom->addItem("HardLight");
    ui->comboBoxBloom->addItem("SoftLight");


}

ImageEffectsDockWidget::~ImageEffectsDockWidget(){
    delete ui;
}


void ImageEffectsDockWidget::on_pushButtonBloom_clicked(){

    QPainter::CompositionMode table[] = {
	QPainter::CompositionMode_Plus,
	QPainter::CompositionMode_Multiply,
	QPainter::CompositionMode_Screen,
	QPainter::CompositionMode_Overlay,
	QPainter::CompositionMode_Darken,
	QPainter::CompositionMode_Lighten,
	QPainter::CompositionMode_HardLight,
	QPainter::CompositionMode_SoftLight
    };

    m_pGraphicsPixmapItem->setPixmap(m_filterBloom->filter(m_pGraphicsPixmapItem->pixmap(),ui->bloomRadius->value(),ui->bloomBrightness->value(),ui->bloomOpacity->value(),table[ui->comboBoxBloom->currentIndex()]));
}

void ImageEffectsDockWidget::on_pushButtonNoiseReduction_clicked(){

    m_thread->setParameteres(ui->spinBoxNoiseReduction->value());
    m_thread->start();
  //  m_pGraphicsPixmapItem->setPixmap(m_filterNoiseReduction->filter(m_pGraphicsPixmapItem->pixmap(),ui->spinBoxNoiseReduction->value()));
}

void ImageEffectsDockWidget::on_pushButtonBlur_clicked()
{  
 m_pGraphicsPixmapItem->setPixmap(m_filterBlur->filter(m_pGraphicsPixmapItem->pixmap(),ui->spinBoxBlur->value()));
}

void ImageEffectsDockWidget::on_pushButtonVingetting_clicked()
{
    m_pGraphicsPixmapItem->setPixmap(m_filterVingetting->filter(m_pGraphicsPixmapItem->pixmap(),ui->spinBoxVingetting->value()));
}

void ImageEffectsDockWidget::on_pushButtonSharpen_clicked()
{
    m_pGraphicsPixmapItem->setPixmap(m_filterSharpen->filter(m_pGraphicsPixmapItem->pixmap(),ui->spinBoxSharpen->value()));
}

void ImageEffectsDockWidget::on_pushButtonAberration_clicked()
{
    m_pGraphicsPixmapItem->setPixmap(m_filterAberration->filter(m_pGraphicsPixmapItem->pixmap(),ui->spinBoxSharpen->value()));
}

void ImageEffectsDockWidget::on_pushButtonRestore_clicked()
{
    m_pGraphicsPixmapItem->setPixmap(*m_basePixmap);
}
