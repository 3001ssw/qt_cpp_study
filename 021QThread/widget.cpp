#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_mythread = new MyThread();

    // 버튼 활성/비활성화
    EnableButton();

    connect(ui->pbtStart, &QPushButton::clicked, this, &Widget::slot_startButtonClicked);
    connect(ui->pbtStop, &QPushButton::clicked, this, &Widget::slot_stopButtonClicked);
    connect(ui->pbtSetPlus, &QPushButton::clicked, this, &Widget::slot_setPlusButtonClicked);

    connect(m_mythread, &MyThread::signal_message, this, &Widget::slot_getMsgFromThread);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::EnableButton()
{
    if (m_mythread->isRunning())
    {
        ui->pbtStart->setEnabled(false);
        ui->pbtStop->setEnabled(true);
    }
    else
    {
        ui->pbtStart->setEnabled(true);
        ui->pbtStop->setEnabled(false);
    }
}

void Widget::slot_startButtonClicked()
{
    m_mythread->start();
    EnableButton();
}

void Widget::slot_stopButtonClicked()
{
    m_mythread->stop();
    m_mythread->wait();
    EnableButton();
}

void Widget::slot_setPlusButtonClicked()
{
    m_mythread->setCountPlus();
}

void Widget::slot_getMsgFromThread(QString msg)
{
    ui->textEdit->append(msg);
}
