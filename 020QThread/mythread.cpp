#include "mythread.h"

#include <QDebug>
#include <QCoreApplication>

MyThread::MyThread()
{
}

void MyThread::run()
{
    qDebug() << "========== start thread";

    for (int i = 0 ; i < 10 ; i++)
    {
        qDebug("========== count: %d", i);
        msleep(1000); // 1초(1000msec) 슬립
    }

    quit();
}
