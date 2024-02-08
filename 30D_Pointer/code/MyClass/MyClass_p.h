#ifndef MYCLASSPRIVATE_H
#define MYCLASSPRIVATE_H

#include "MyClass.h"

class MyClassPrivate
{
    Q_DECLARE_PUBLIC(MyClass) // 예약어 사용
public:
    MyClassPrivate(MyClass* q);
    ~MyClassPrivate();

private:
    int m_value;
    MyClass *q_ptr; // q_ptr로 해야함

    void setValue(int value);
    int getValue();

    void printValue();
};

#endif // MYCLASSPRIVATE_H
