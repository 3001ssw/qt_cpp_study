#include "MyClass.h"
#include "MyClass_p.h"
#include <QDebug>

MyClass::MyClass()
{
    d_ptr = new MyClassPrivate(this); // private class 생성

}

MyClass::~MyClass()
{

}

void MyClass::setValue(int value)
{
    m_value = value;

    Q_D(MyClass); // d 사용 전 Q_D 해야 함
    d->setValue(value * 10);
}

int MyClass::getValue()
{
    return m_value;
}

void MyClass::printValueAll()
{
    Q_D(MyClass); // d 사용 전 Q_D 해야 함
    d->printValue();
}
