#include "imagepropertiesdockwidget.h"
#include "ui_imagepropertiesdockwidget.h"

ImagePropertiesDockWidget::ImagePropertiesDockWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ImagePropertiesDockWidget)
{
    ui->setupUi(this);
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setMinimumSize(200,200);
}

ImagePropertiesDockWidget::~ImagePropertiesDockWidget(){
    delete ui;
}
