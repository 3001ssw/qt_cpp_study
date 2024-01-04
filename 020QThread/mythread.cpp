#include "mythread.h"

#include <QDebug>

MyThread::MyThread()
{

}

void MyThread::run()
{
    for (int i = 0 ; i < 10 ; i++)
    {
        qDebug("count: %d", i);
        msleep(100);
    }
}
