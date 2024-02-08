#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

public slots:
    void slot_userDateChanged(const QDate &date); // QDateEdit 슬롯 함수
    void slot_userTimeChanged(const QTime &time); // QTimeEdit 슬롯 함수
    void slot_dateTimeChanged(const QDateTime &dateTime); // QDateTimeEdit 슬롯
};
#endif // WIDGET_H
