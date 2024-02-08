#include "MyClass.h"
#include "MyClass_p.h"
#include <QDebug>

MyClass::MyClass()
{
    d_ptr = new MyClassPrivate(this);

}

MyClass::~MyClass()
{

}

void MyClass::setValue(int value)
{
    m_value = value;

    Q_D(MyClass);
    d->setValue(value * 10);
}

int MyClass::getValue()
{
    return m_value;
}

void MyClass::printValueAll()
{
    Q_D(MyClass);
    d->printValue();
}
