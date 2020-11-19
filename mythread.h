#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QMutex>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class MyThread : public QThread
{
   Q_OBJECT

public slots:

    void motor1(float value);
    void motor2();
    void motor3();
    void motor4();


    void run();

};


#endif // MYTHREAD_H
