#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->spinBox->setRange(-100, 100); // 범위
    ui->spinBox->setValue(0); // 값
    ui->spinBox->setPrefix(QString("Pre-")); // Prefix
    ui->spinBox->setSuffix(QString("-Suffix")); // Suffix
    ui->spinBox->setDisplayIntegerBase(16); // 진수
    ui->spinBox->setSingleStep(5); // 증감 되는 크기

    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSpinBox(int))); // 시그널&슬롯 연결


    ui->doubleSpinBox->setRange(0.000, 100.000); // 범위
    ui->doubleSpinBox->setValue(0.000); // 값
    ui->doubleSpinBox->setPrefix(QString("Pre ")); // Prefix
    ui->doubleSpinBox->setSuffix(QString(" Suffix")); // Suffix
    ui->doubleSpinBox->setDecimals(2); // 소수점 자리수
    ui->doubleSpinBox->setSingleStep(0.05); // 증감 되는 크기

    connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(valueChangedDoubleSpinBox(double))); // 시그널&슬롯 연결
}

Widget::~Widget()
{
    delete ui;
}

void Widget::valueChangedSpinBox(int value)
{
    QString str = QString("spinbox value: %1").arg(value);
    ui->label_spinbox->setText(str);
}

void Widget::valueChangedDoubleSpinBox(double value)
{
    QString str = QString("doublespinbox value: %1").arg(value);
    ui->label_doublespinbox->setText(str);
}

