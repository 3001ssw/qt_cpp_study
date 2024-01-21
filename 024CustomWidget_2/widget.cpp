#include "widget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(nullptr, Qt::FramelessWindowHint)
{
    Q_UNUSED(parent);

    m_device = QPixmap(":/img/background.png");
    QBitmap bmp = m_device.createHeuristicMask();
    setFixedSize(m_device.size());
    setMask(bmp);

    m_pbtnButton = new QPushButton("hi", this);

    connect(m_pbtnButton, &QPushButton::pressed, this, &Widget::slot_Button);

    m_pbtnButton->setGeometry(60, 150, 70, 30);

}

Widget::~Widget()
{
}

void Widget::slot_Button()
{
    qDebug() << "Q_FUNC_IFO";
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.drawPixmap(event->rect(), m_device);

    painter.setPen(QColor(119, 119, 119));
    painter.setBrush(QColor(119, 119, 119));
    painter.drawRect(29, 76, 228, 356);
}

