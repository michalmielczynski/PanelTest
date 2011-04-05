#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>
#include <QGraphicsPixmapItem>


class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(QObject *parent,QGraphicsPixmapItem *pixmapItem);
    void run();


    void setParameteres( int size);
    QString name;

private:
    QPixmap filter(QPixmap &inPixmap, int size);
    QPixmap m_pixmap;
    QGraphicsPixmapItem *m_pixmapItem;
    int size;

public slots:
    void setPixmap();

};

#endif // MYTHREAD_H
