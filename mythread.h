#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>
#include <QGraphicsPixmapItem>


class MyThread : public QThread, QObject
{
    Q_OBJECT
public:
    MyThread(QObject *parent);
    void run();


    void setParameteres(QGraphicsPixmapItem *p,QPixmap *inPixmap, int size);
    QString name;

private:
    QPixmap filter(QPixmap &inPixmap, int size);
    QPixmap *m_pPixmap;
    QPixmap m_pixmap;
    QGraphicsPixmapItem *m_pixampItem;
    int size;

public slots:
    void setPixmap();

};

#endif // MYTHREAD_H
