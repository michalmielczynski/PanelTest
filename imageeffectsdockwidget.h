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

<<<<<<< HEAD
private slots:
    void on_horizontalSlider_sliderMoved(int position);

signals:
    void blur(int value);

=======
    void on_horizontalSlider_sliderMoved(int position);
>>>>>>> f296ac5ac9fa9f30f99e612ff9cad3988f36245c
private:
    Ui::ImageEffectsDockWidget *ui;
};

#endif // IMAGEEFFECTSDOCKWIDGET_H
