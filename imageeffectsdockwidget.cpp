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
<<<<<<< HEAD
    emit blur(ui->horizontalSlider->value());
}




=======
    /// @todo blur code here, please
}
>>>>>>> f296ac5ac9fa9f30f99e612ff9cad3988f36245c
