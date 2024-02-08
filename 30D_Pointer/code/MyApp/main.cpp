#include <QCoreApplication>

#include "MyClass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    MyClass my;
    my.setValue(10);
    my.printValueAll();

    return a.exec();
}
