#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->hSlider->setRange(0, 200); // 범위 설정
    ui->hSlider->setSliderPosition(0); // 포지션 설정
    ui->hSlider->setSingleStep(20); // 방향키 클릭 시 증/감 크기
    ui->hSlider->setPageStep(50); // page up/down 키 클릭 시 증/감 하는 값 크기
//    ui->hSlider->setOrientation(Qt::Orientation::Horizontal); // 수평/수직 설정

    ui->hSlider->setTickPosition(QSlider::TickPosition::TicksBelow); // Tick 포지션
    ui->hSlider->setTickInterval(10); // Tick 간격

//    ui->hSlider->setTracking(false); // 트래킹 활성화 여부. false일 경우 조작이 끝날때만 신호 보냄
//    ui->hSlider->setInvertedAppearance(true); // 표시 반대로(왼쪽으로 갈수록 값이 커짐)
//    ui->hSlider->setInvertedControls(true); // 조작 반대로(PageUp키 누르면 값이 작아짐)

    connect(ui->hSlider, SIGNAL(valueChanged(int)), this, SLOT(slot_valueChanged(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_valueChanged(int value)
{
    QString strVal = QString("%1").arg(value);
    ui->leVal->setText(strVal);
}

