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

private slots:
    void slot_start();
    void slot_stop();
    void slot_isrunning();

    void slot_count(int count);

    void slot_started();
    void slot_finished();
};
#endif // WIDGET_H
