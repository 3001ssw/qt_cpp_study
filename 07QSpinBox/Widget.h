#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

public slots:
    void valueChangedSpinBox(int value); // QSpinBox 슬롯함수
    void valueChangedDoubleSpinBox(double value); // QDoubleSpinBox 슬롯함수
};
#endif // WIDGET_H
