#include <QCoreApplication>

#include "mythread.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mythread;
    mythread.start();

    mythread.wait();
    qDebug() << "my thread finished";

    return a.exec();
}
