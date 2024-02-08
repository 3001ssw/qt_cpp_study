#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtGlobal>
#include "MyClass_global.h"

class MyClassPrivate;
class MYCLASS_EXPORT MyClass
{
    Q_DECLARE_PRIVATE(MyClass) // 예약어 사용

public:
    MyClass();
    ~MyClass();

private:
    int m_value;
    MyClassPrivate *d_ptr; // d_ptr로 해야함

public:
    void setValue(int value);
    int getValue();

    void printValueAll();
};

#endif // MYCLASS_H
