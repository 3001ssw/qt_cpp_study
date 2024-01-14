#include <QCoreApplication>

#include <QtConcurrent>
#include <QDebug>

int sum(int iX, int iY)
{
    int iSum = iX + iY;

    qDebug("%d + %d = %d", iX, iY, iSum);

    return iSum;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFuture<int> f1 = QtConcurrent::run(sum, 1, 2);
    f1.waitForFinished();

    return a.exec();
}
