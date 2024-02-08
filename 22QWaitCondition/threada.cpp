#include "threada.h"

ThreadA::ThreadA(QObject *parent)
    : QThread{parent}
{

}

void ThreadA::run()
{
    for (int i = 0; i < 10; ++i)
    {
        msleep(10);
    }
}
