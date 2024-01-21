#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QPixmap m_device;
    QPushButton *m_pbtnButton;

private slots:
    void slot_Button();

protected:
    virtual void paintEvent(QPaintEvent* event);
};
#endif // WIDGET_H
