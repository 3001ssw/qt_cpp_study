#include "mythread.h"

#include <QDebug>

MyThread::MyThread(QObject *parent)
    : QThread{parent}
{
    m_bThreadStop = false;
}

void MyThread::stop()
{
    m_bThreadStop = true;
}

void MyThread::run()
{
    m_bThreadStop = false;
    int count = 0;

    while (!m_bThreadStop)
    {
        m_mutex.lock();

        count++;
        msleep(500);
        emit signal_count(count);

        m_mutex.unlock();

        msleep(500);
    }
}
