#include "mythread.h"

#include <QDebug>

MyThread::MyThread(QObject *parent)
    : QThread{parent}
{
    m_iCount = 0;
}

int MyThread::GetCount()
{
    m_mutex.lock();
    int iRes = m_iCount;
    m_mutex.unlock();
    return iRes;
}

void MyThread::run()
{
    for (int i = 0 ; i < 10 ; i++)
    {
        m_mutex.lock();

        m_iCount++;
        msleep(500);
        qDebug() << "count: " << m_iCount;
        m_mutex.unlock();

        msleep(500);
    }
}
