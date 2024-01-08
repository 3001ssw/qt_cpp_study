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

void MyThread::setCountPlus()
{
    // m_mutex.lock();

    int iOld = m_count;
    m_count++; // 1 증가
    QString msg = QString("값 증가: %1 -> %2").arg(iOld).arg(m_count);
    emit signal_message(msg);

    // m_mutex.unlock();
}

void MyThread::run()
{
    m_count = 0;
    m_bThreadStop = false;

    while (!m_bThreadStop)
    {
        // m_mutex.lock();

        // 시작 값
        int iStart = m_count;
        QString msg = QString("=========== 시작: %1").arg(iStart);
        emit signal_message(msg);

        msleep(300); // 특정 작업이 300msec이 걸린다고 가정

        // 종료 값
        int iEnd = m_count;
        msg = QString("=========== 종료: %1").arg(iEnd);
        emit signal_message(msg);

        if (iStart != iEnd)
        {
            msg = QString("=========== 시작 할때와 종료할 때 값이 달라졌습니다.");
            emit signal_message(msg);
        }

        // 작업 다 끝나면 1 증가
        m_count++;

        // m_mutex.unlock();

        msleep(1000); // 쓰레드 주기 1000msec
    }
}
