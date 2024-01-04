#include <QCoreApplication>

#include <QObject>
#include <QDebug>

#include "mythread.h"

void slot_started()
{
    qDebug() << Q_FUNC_INFO;
}

void slot_finished()
{
    qDebug() << Q_FUNC_INFO;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mythread;

    QObject::connect(&mythread, &MyThread::started, slot_started);
    QObject::connect(&mythread, &MyThread::finished, slot_finished);

    mythread.start();

    mythread.wait();

    qDebug() << "exit";
    return a.exec();
}
