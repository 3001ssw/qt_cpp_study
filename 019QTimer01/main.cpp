#include <QCoreApplication>

#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto func = []()->void{qDebug() << "single shot";};

    QTimer::singleShot(3000, &a, func);

    qDebug() << "exit";

    return a.exec();
}
