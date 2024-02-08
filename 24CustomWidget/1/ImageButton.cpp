#include "ImageButton.h"

#include <QPainter>

enum BEHAVIOR
{
    NORMAL = 0,
    ENTER,
    LEAVE,
    PRESS,
    DISABLE,
};

ImageButton::ImageButton(QWidget *parent)
    : QWidget(parent)
{
    m_behavior = BEHAVIOR::NORMAL;
    m_disabled = false;

    QImage img(":/images/button_normal.png");
    setFixedSize(QSize(img.width(), img.height()));
}

void ImageButton::setDisabled(bool bSetDisable)
{
    if (m_disabled == bSetDisable)
        return;

    m_disabled = bSetDisable;

    update();
}

void ImageButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;
    painter.begin(this);

    if (m_disabled)
        m_imgFileName = QString(":/images/button_disable.png");
    else
    {
        if (m_behavior == BEHAVIOR::NORMAL)
            m_imgFileName = QString(":/images/button_normal.png");
        if (m_behavior == BEHAVIOR::ENTER)
            m_imgFileName = QString(":/images/button_hover.png");
        if (m_behavior == BEHAVIOR::LEAVE)
            m_imgFileName = QString(":/images/button_normal.png");
        if (m_behavior == BEHAVIOR::PRESS)
            m_imgFileName = QString(":/images/button_press.png");
        if (m_behavior == BEHAVIOR::DISABLE)
            m_imgFileName = QString(":/images/button_disable.png");
    }

    QImage img(m_imgFileName);

    painter.drawImage(0, 0, img);
    painter.end();
}

void ImageButton::enterEvent(QEnterEvent *event)
{
    Q_UNUSED(event);
    m_behavior = BEHAVIOR::ENTER;
    emit mouseHovering();
    update();
}

void ImageButton::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    m_behavior = BEHAVIOR::LEAVE;
    update();
}

void ImageButton::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_behavior = BEHAVIOR::PRESS;
    emit mouseClciked();
    update();
}

void ImageButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_behavior = BEHAVIOR::PRESS;
    update();
}

void ImageButton::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_behavior = BEHAVIOR::ENTER;
    update();
}
