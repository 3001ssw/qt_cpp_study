#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *m_pButton;
    int m_iNumber;

    QLabel *m_pLabel;

private slots:
    void slot_btn_push();
};
#endif // WIDGET_H
