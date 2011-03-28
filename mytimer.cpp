#include "mytimer.h"
#include <QtCore>

MyTimer::MyTimer(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    timer->setInterval(1);
    connect(timer,SIGNAL(timeout()),this,SLOT(mySlot()));
}

void MyTimer::mySlot()
{
    qDebug()<<"Timer:"<<time;
    time++;
}
