#include <QCoreApplication>

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>

int number = 0;

class ThreadA : public QThread
{
    Q_OBJECT
public:
    ThreadA() {};

protected:
    virtual void run()
    {
        for (int i = 0; i < 10; ++i)
        {
            number++;
            msleep(10);
        }
    };
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ThreadA threadA;
//    ThreadB threadB;

    threadA.start();
//    threadB.start();

    threadA.wait();
//    threadB.wait();

    return a.exec();
}
