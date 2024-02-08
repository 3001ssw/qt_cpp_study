#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->hSlider->setRange(0, 200); // 범위 설정
    ui->hSlider->setSliderPosition(0); // 포지션 설정
    ui->hSlider->setSingleStep(5); // 방향키 클릭 시 증/감 크기

    ui->progressBar->setRange(0, 200); // 범위 설정
    ui->progressBar->setValue(0); // 포지션 설정
//    ui->progressBar->setTextVisible(false); // 텍스트 표시 안함
    ui->progressBar->setFormat("%p 퍼센트"); // 텍스트 포맷
//    ui->progressBar->setFormat("%p% 진행 중 (%v/%m)"); // 텍스트 포맷
//    ui->progressBar->setAlignment(Qt::AlignHCenter); // 텍스트 표시 위치

    connect(ui->hSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
}

Widget::~Widget()
{
    delete ui;
}


