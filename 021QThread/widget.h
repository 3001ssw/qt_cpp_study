#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"

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

protected:
    MyThread *m_mythread;

    void EnableButton();

private slots:
    void slot_startButtonClicked();
    void slot_stopButtonClicked();
    void slot_setPlusButtonClicked();

    void slot_getMsgFromThread(QString msg);
};
#endif // WIDGET_H
