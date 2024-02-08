#include <QCoreApplication>

#include <QtConcurrent>
#include <QDebug>

void print_for_loop(int iLoopCnt)
{
    for (int iIndex = 0 ; iIndex < iLoopCnt ; iIndex++)
    {
        qDebug("print: %d", iIndex);
        QThread::sleep(1);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFuture<void> func = QtConcurrent::run(print_for_loop, 10);

    qDebug("main thread wait befor function finished");
    func.waitForFinished();
    qDebug("finished");

    return a.exec();
}
