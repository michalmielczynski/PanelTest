#ifndef IMAGEPROPERTIESDOCKWIDGET_H
#define IMAGEPROPERTIESDOCKWIDGET_H

#include <QDockWidget>

namespace Ui {
    class ImagePropertiesDockWidget;
}

class ImagePropertiesDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit ImagePropertiesDockWidget(QWidget *parent = 0);
    ~ImagePropertiesDockWidget();

private:
    Ui::ImagePropertiesDockWidget *ui;
};

#endif // IMAGEPROPERTIESDOCKWIDGET_H
