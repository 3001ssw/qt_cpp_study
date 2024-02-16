#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    initalizeWidget();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initalizeWidget()
{
    setWindowTitle("TCP Client");

    m_pSocket = new QTcpSocket(this);

    connect(ui->pbtConnect, &QPushButton::clicked, this, &Widget::slot_connectServer); // connect
    connect(ui->pbtDisconnect, &QPushButton::clicked, this, &Widget::slot_DisconnectServer); // disconnect
    connect(m_pSocket, &QTcpSocket::readyRead, this, &Widget::slot_readMessage); // read message
    connect(m_pSocket, &QTcpSocket::disconnected, this, &Widget::slot_disconnected);// disconnect

}

void Widget::slot_connectServer()
{
    QString strIP = ui->leServerIP->text();
    strIP = strIP.trimmed(); // 공백 제거

    QHostAddress serverAddress(strIP);

    m_pSocket->connectToHost(serverAddress, 8888);
}

void Widget::slot_DisconnectServer()
{
    m_pSocket->disconnect();
    m_pSocket->close();
    ui->edMsg->append("Disconnected Server");
}

void Widget::slot_readMessage()
{
    if (0 <= m_pSocket->bytesAvailable())
    {
        QByteArray readDAta = m_pSocket->readAll();
        ui->edMsg->append(readDAta);
    }
}

void Widget::slot_disconnected()
{
    ui->edMsg->append("Disconnected Server");
}

