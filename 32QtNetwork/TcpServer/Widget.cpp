#include "Widget.h"
#include "ui_Widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    initailizeWidget();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initailizeWidget()
{
    setWindowTitle("TCP Server");

    QHostAddress hostAddress;
    QList<QHostAddress> ipAddressList = QNetworkInterface::allAddresses(); // 모든 ip 주소 얻기
    for (int iIndex = 0 ; iIndex < ipAddressList.size() ; iIndex++)
    {
        // ip v4 주소 얻기
        QHostAddress hostAddressTemp = ipAddressList.at(iIndex);
        if (hostAddressTemp.toIPv4Address())
        {
            hostAddress = hostAddressTemp;
            break;
        }
    }

    // 127.0.0.1
    if (hostAddress.toString().isEmpty())
        hostAddress = QHostAddress(QHostAddress::LocalHost);

    m_pTcpServer = new QTcpServer(this);
    // listen
    bool bListen = m_pTcpServer->listen(hostAddress, 8888);
    if (bListen == false)
    {
        QMessageBox::critical(this, "TCP Server", QString("listen fail: %1").arg(m_pTcpServer->errorString()));
        close();
        return;
    }
    ui->lbStatus->setText("서버 동작");
    ui->lbIP->setText(QString("IP: %1").arg(hostAddress.toString()));
    ui->lbPort->setText(QString("PORT: %1").arg(m_pTcpServer->serverPort()));

    connect(m_pTcpServer, &QTcpServer::newConnection, this, &Widget::slot_newConnect);
    ui->edMsg->clear();
}

void Widget::slot_newConnect()
{
    QTcpSocket *pClient = m_pTcpServer->nextPendingConnection(); // 접속한 클라이언트의 정보 저장
    connect(pClient, &QTcpSocket::disconnected, pClient, &Widget::deleteLater); // 클라이언트가 disconnect되면 나중에 메모리에서 소멸
    connect(pClient, &QTcpSocket::disconnected, this, &Widget::slot_disconnectClient); // 클라이언트가 disconnect되면 나중에 메모리에서 소멸

    QString strTime = QTime::currentTime().toString("hh:mm:ss");
    QHostAddress peerAddress = pClient->peerAddress();
    quint16 unPeerPort = pClient->peerPort();
    QString strMsg = QString("%1: 클라이언트(%2:%3) 접속")
                         .arg(strTime)
                         .arg(peerAddress.toString())
                         .arg(unPeerPort);

    ui->edMsg->append(strMsg);

    // client로 메시지 전달
    QByteArray message = QByteArray("complet connect server");
    pClient->write(message);
    //    pClient->disconnectFromHost(); // 종료
}

void Widget::slot_disconnectClient()
{
    QTcpSocket *pClient = static_cast<QTcpSocket*>(sender());

    QString strTime = QTime::currentTime().toString("hh:mm:ss");
    QHostAddress peerAddress = pClient->peerAddress();
    quint16 unPeerPort = pClient->peerPort();
    QString strMsg = QString("%1: 클라이언트(%2:%3) 접속해제")
                         .arg(strTime)
                         .arg(peerAddress.toString())
                         .arg(unPeerPort);
    ui->edMsg->append(strMsg);
}
