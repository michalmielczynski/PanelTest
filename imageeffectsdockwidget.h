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
    /// @todo effect methods here


private slots:
    /// @note this is OK, but should internally call public "effect" method;
    void on_horizontalSlider_sliderMoved(int position);

signals:
    void blur(int value);



private:
    Ui::ImageEffectsDockWidget *ui;
};

#endif // IMAGEEFFECTSDOCKWIDGET_H
