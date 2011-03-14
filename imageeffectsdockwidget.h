#ifndef IMAGEEFFECTSDOCKWIDGET_H
#define IMAGEEFFECTSDOCKWIDGET_H

#include <QDockWidget>

namespace Ui {
    class ImageEffectsDockWidget;
}

class ImageEffectsDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit ImageEffectsDockWidget(QWidget *parent = 0);
    ~ImageEffectsDockWidget();

private:
    Ui::ImageEffectsDockWidget *ui;
};

#endif // IMAGEEFFECTSDOCKWIDGET_H
