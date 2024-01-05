#include <QCoreApplication>

#include <QObject>
#include <QDebug>
#include <QThread>

#include "mythread.h"

// Thread 시작 시그널을 받기위한 함수
void slot_started()
{
    qDebug() << "--- slot function: " << Q_FUNC_INFO;
}

// Thread 종료 시그널을 받기위한 함수
void slot_finished()
{
    qDebug() << "--- slot function: " << Q_FUNC_INFO;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mythread;
    // qDebug() << "isRunning: " << mythread.isRunning(); // run?
    // qDebug() << "isFinished: " << mythread.isFinished(); // Finished?

    QObject::connect(&mythread, &MyThread::started, slot_started); // 쓰레드 시작 signal 함수 연결
    QObject::connect(&mythread, &MyThread::finished, slot_finished); // 쓰레드 종료 signal 함수 연결

    mythread.start();
    // qDebug() << "isRunning: " << mythread.isRunning(); // run?
    // qDebug() << "isFinished: " << mythread.isFinished(); // Finished?

    mythread.wait(); // 종료할 때까지 대기
    // qDebug() << "isRunning: " << mythread.isRunning(); // run?
    // qDebug() << "isFinished: " << mythread.isFinished(); // Finished?

    return a.exec();
}
