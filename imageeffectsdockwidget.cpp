#include "imageeffectsdockwidget.h"
#include "ui_imageeffectsdockwidget.h"

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

ImageEffectsDockWidget::ImageEffectsDockWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ImageEffectsDockWidget)
  /// @todo pass QPixmap pointer here
{
    ui->setupUi(this);
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setMinimumSize(200,200);
}

ImageEffectsDockWidget::~ImageEffectsDockWidget()
{
    delete ui;
}

void ImageEffectsDockWidget::on_horizontalSlider_sliderMoved(int position)
{
    /// @note remove unwanted empty lines. Use only ONE empty line to separate some code blocks.
    emit blur(position);
}


