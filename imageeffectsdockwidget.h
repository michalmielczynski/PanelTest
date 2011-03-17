#ifndef IMAGEEFFECTSDOCKWIDGET_H
#define IMAGEEFFECTSDOCKWIDGET_H

#include <QDockWidget>
#include <QGraphicsPixmapItem>

namespace Ui {
    class ImageEffectsDockWidget;
}

class ImageEffectsDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit ImageEffectsDockWidget(QGraphicsPixmapItem *p,QWidget *parent = 0);
    ~ImageEffectsDockWidget();
    void blurImage(int blurRange);

private slots:
    /// @note this is OK, but should internally call public "effect" method;
    void on_horizontalSlider_sliderMoved(int position);

signals:
void updateScene();

private:
    Ui::ImageEffectsDockWidget *ui;
    QGraphicsPixmapItem *m_pGraphicsPixmapItem;

};

#endif // IMAGEEFFECTSDOCKWIDGET_H
