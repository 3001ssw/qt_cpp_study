#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 년: yy(2자리 숫자), yyyy(4자리 숫자)
    // 월: M, MM(2자리 숫자), MMM(3자리 문자, Jan), MMMM(풀네임, January)
    // 일: d, dd(2자리 숫자), ddd(요일, Mon), dddd(풀네임, Monday)
    // 시: h, hh(2자리 숫자)
    // 분: m, mm(2자리 숫자)
    // 초: s, ss(2자리 숫자)
    // 밀리초: z, zzz(3자리 숫자)
    // 오전/오후, AM/PM: AP
    // 오전/오후, am/pm: ap
    ui->dateEdit->setDisplayFormat("yyyy/MMMM/dd"); // ex) 2023/10월/27일
    ui->dateEdit->setDate(QDate::currentDate());
    connect(ui->dateEdit, SIGNAL(userDateChanged(QDate)), this, SLOT(slot_userDateChanged(QDate)));

    ui->timeEdit->setDisplayFormat("hh:mm:ss"); // ex) 13:39:17
    ui->timeEdit->setTime(QTime::currentTime());
    connect(ui->timeEdit, SIGNAL(userTimeChanged(QTime)), this, SLOT(slot_userTimeChanged(QTime)));

    ui->dateTimeEdit->setDisplayFormat("yy년 MM월 dd일 hh시mm분ss초"); // 23년 10월 27일 13시39분17초
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    connect(ui->dateTimeEdit, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(slot_dateTimeChanged(QDateTime)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_userDateChanged(const QDate &date)
{
    QString str = date.toString("yy/MM/dd");
    ui->lbDate->setText(str);
}

void Widget::slot_userTimeChanged(const QTime &time)
{
    QString str = time.toString("hh시 mm분 ss초");
    ui->lbTime->setText(str);
}

void Widget::slot_dateTimeChanged(const QDateTime &dateTime)
{
    QString str = dateTime.toString("yyyy/MM/dd hh:mm:ss");
    ui->lbDateTime->setText(str);
}

