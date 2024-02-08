#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->dial->setRange(0, 100); // 범위 설정
    ui->dial->setSliderPosition(0); // 포지션 설정
    ui->dial->setSingleStep(5); // single step 설정
    ui->dial->setPageStep(10); // page step 설정

    ui->dial->setNotchesVisible(true); // 노치 보이게
    ui->dial->setWrapping(true); // 래핑 설정. 최소값-최대값을 연결

    connect(ui->dial, SIGNAL(valueChanged(int)), this, SLOT(slot_valueChanged(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_valueChanged(int value)
{
    QString str_dial = QString("dial value: %1").arg(value);
    ui->label->setText(str_dial);
}
