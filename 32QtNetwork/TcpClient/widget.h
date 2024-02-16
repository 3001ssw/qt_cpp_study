#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

private:
    QTcpSocket *m_pSocket;

    void initalizeWidget();

private slots:
    void slot_connectServer();
    void slot_DisconnectServer();
    void slot_readMessage();
    void slot_disconnected();
};
#endif // WIDGET_H
