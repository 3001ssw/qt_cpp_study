#include "MyClass_p.h"
#include <QDebug>

MyClassPrivate::MyClassPrivate(MyClass* q)
{
    q_ptr = q; // 인자로 받아야함
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
    Q_Q(MyClass); // q 사용 전 Q_Q 호출
    qDebug() << "MyClass::printValue: " << q->getValue();
    qDebug() << "MyClassPrivate::printValue: " << m_value;
}
