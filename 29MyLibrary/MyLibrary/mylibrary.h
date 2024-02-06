#ifndef MYLIBRARY_H
#define MYLIBRARY_H

#include "MyLibrary_global.h"

class MYLIBRARY_EXPORT MyLibrary
{
public:
    MyLibrary();

public:
    qint32 getSum(qint32 x, quint32 y);
};

#endif // MYLIBRARY_H
