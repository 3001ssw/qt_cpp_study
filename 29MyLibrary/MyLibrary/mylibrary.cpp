#include "mylibrary.h"

MyLibrary::MyLibrary()
{
}

qint32 MyLibrary::getSum(qint32 x, quint32 y)
{
    quint32 sum = x + y;
    return sum;
}
