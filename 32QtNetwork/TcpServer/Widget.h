#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    QTcpServer *m_pTcpServer;

protected:
    void initailizeWidget();

private slots:
    void slot_newConnect();
    void slot_disconnectClient();

};
#endif // WIDGET_H
