#include <QCoreApplication>

#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QWaitCondition>

int number = 0;

QMutex mutex;
QWaitCondition waitcondition;

class ThreadA : public QThread
{
public:
    ThreadA() {};

protected:
    void run() override
    {
        qDebug() << "ThreadA::run " << number;
        for (int i = 0; i < 10; ++i)
        {
//            sleep(1);
//            msleep(1);
            usleep(1);

            mutex.lock();
            number++;
            waitcondition.wakeAll();
            mutex.unlock();


        }
    };
};

class ThreadB : public QThread
{
public:
    ThreadB() {};

protected:
    void run() override
    {
        qDebug() << "ThreadB::run " << number;
        for (int i = 0; i < 10; ++i)
        {
            mutex.lock();
            waitcondition.wait(&mutex);
            qDebug() << "number: " << number;
            mutex.unlock();

        }
    };
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ThreadA threadA;
    ThreadB threadB;

    threadA.start();
    threadB.start();

    threadA.wait();
    threadB.wait();

    return a.exec();
}
