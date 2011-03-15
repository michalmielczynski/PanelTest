#include "imageeffectsdockwidget.h"
#include "ui_imageeffectsdockwidget.h"

ImageEffectsDockWidget::ImageEffectsDockWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ImageEffectsDockWidget)
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

    emit blur(ui->horizontalSlider->value());
}


