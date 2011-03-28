#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTimer>
#include <QObject>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer(QObject *parent);
    QTimer *timer;
    int time;

public slots:
    void mySlot();

};

#endif // MYTIMER_H
