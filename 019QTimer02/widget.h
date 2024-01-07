#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

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
    QTimer *m_timer; // QTimer 변수 생성

public slots:
    void slot_startClicked(); // 시작 버튼
    void slot_stopClicked(); // 정지 버튼
    void slot_singleShotClicked(); // single shot 버튼

    void slot_timeout(); // 일정 시간 간격으로 실행하는 slot 함수
    void slot_singleShot(); // 일정 시간 뒤 실행하는 slot 함수
};
#endif // WIDGET_H
