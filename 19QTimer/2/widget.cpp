#include "widget.h"
#include "ui_widget.h"

#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 버튼 활성화/비활성화
    ui->pbtStart->setEnabled(true);
    ui->pbtStop->setEnabled(false);

    // start, stop, singleShot 버튼 connect
    connect(ui->pbtStart, &QPushButton::clicked, this, &Widget::slot_startClicked);
    connect(ui->pbtStop, &QPushButton::clicked, this, &Widget::slot_stopClicked);
    connect(ui->pbtSingleShot, &QPushButton::clicked, this, &Widget::slot_singleShotClicked);

    // 타이머
    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &Widget::slot_timeout); // start 함수 호출 시 slot_timeout 함수 호출
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_startClicked()
{
    ui->pbtStart->setEnabled(false);
    ui->pbtStop->setEnabled(true);
    m_timer->start(1000); // 타이머 1초 간격마다 실행
}

void Widget::slot_stopClicked()
{
    ui->pbtStart->setEnabled(true);
    ui->pbtStop->setEnabled(false);
    m_timer->stop(); // 타이머 종료
}

void Widget::slot_singleShotClicked()
{
    QDateTime current = QDateTime::currentDateTime();
    QString timeStr;
    timeStr = current.toString("3초 뒤 표시(현재 yyyy-MM-dd hh:mm:ss zzz)");
    ui->lbSingleShot->setText(timeStr);

    QTimer::singleShot(3000, this, &Widget::slot_singleShot); // 3초 후에 slot_singleShot 함수 호출
}

void Widget::slot_timeout()
{
    QDateTime current = QDateTime::currentDateTime();
    QString timeStr;
    timeStr = current.toString("현재 yyyy-MM-dd hh:mm:ss zzz");
    ui->lbTime->setText(timeStr);
}

void Widget::slot_singleShot()
{
    QDateTime current = QDateTime::currentDateTime();
    QString timeStr;
    timeStr = current.toString("현재 yyyy-MM-dd hh:mm:ss zzz");
    ui->lbSingleShot->setText(timeStr);
}

