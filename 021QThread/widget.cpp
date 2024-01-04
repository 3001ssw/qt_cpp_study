#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_mythread = new MyThread();

    connect(ui->pbtStart, &QPushButton::clicked, this, &Widget::slot_start);
    connect(ui->pbtStop, &QPushButton::clicked, this, &Widget::slot_stop);
    connect(ui->pbtIsRunnig, &QPushButton::clicked, this, &Widget::slot_isrunning);

    connect(m_mythread, &MyThread::signal_count, this, &Widget::slot_count);
    connect(m_mythread, &MyThread::started, this, &Widget::slot_started);
    connect(m_mythread, &MyThread::finished, this, &Widget::slot_finished);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_start()
{
    m_mythread->start();
}

void Widget::slot_stop()
{
    m_mythread->stop();
}

void Widget::slot_isrunning()
{
    bool bRunning = m_mythread->isRunning();
    QString msg = QString("is running: %1").arg(bRunning);
    ui->textEdit->append(msg);
}

void Widget::slot_count(int count)
{
    QString msg = QString("count: %1").arg(count);
    ui->textEdit->append(msg);
}

void Widget::slot_started()
{
    qDebug() << Q_FUNC_INFO;
    ui->textEdit->append("thread started");
}

void Widget::slot_finished()
{
    qDebug() << Q_FUNC_INFO;
    ui->textEdit->append("thread finished");
}

