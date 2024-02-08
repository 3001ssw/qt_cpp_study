#include "MyClass_p.h"
#include <QDebug>

MyClassPrivate::MyClassPrivate(MyClass* q)
{
    q_ptr = q;
}

MyClassPrivate::~MyClassPrivate()
{

}

void MyClassPrivate::setValue(int value)
{
    m_value = value;
}

int MyClassPrivate::getValue()
{
    return m_value;
}

void MyClassPrivate::printValue()
{
    Q_Q(MyClass);
    qDebug() << "MyClass::printValue: " << q->getValue();
    qDebug() << "MyClassPrivate::printValue: " << m_value;
}
