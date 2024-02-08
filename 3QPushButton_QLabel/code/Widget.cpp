#include "Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_iNumber = 0;

    setFixedSize(300, 200);

    m_pButton = new QPushButton("버튼", this);
    m_pButton->setGeometry(10, 10, 100, 30);

    connect(m_pButton, SIGNAL(pressed()), this, SLOT(slot_btn_push()));

    m_pLabel = new QLabel(this);
    m_pLabel->setGeometry(10, 40, 100, 30);
}

Widget::~Widget()
{

}

void Widget::slot_btn_push()
{
    m_iNumber++;
    QString str = QString("Number: %1").arg(m_iNumber);
    m_pLabel->setText(str);
}
