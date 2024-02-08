#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1번 라디오 버튼만 체크
    ui->radioButton1->setChecked(true);
    ui->radioButton2->setChecked(false);
    ui->radioButton3->setChecked(false);
    // 1번 라디오 버튼 체크됐다고 라벨에 표시
    QString str = QString("clicked button: %1").arg(ui->radioButton1->text());
    ui->label->setText(str);

    // 버튼 그룹에 라디오버튼 1~3 추가
    m_group = new QButtonGroup(this);
    m_group->addButton(ui->radioButton1);
    m_group->addButton(ui->radioButton2);
    m_group->addButton(ui->radioButton3);
    m_group->setExclusive(true); // Exclusive 설정

    // 클릭 시그널, 슬롯 연결
    connect(m_group, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(slot_buttonClicked(QAbstractButton*)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_buttonClicked(QAbstractButton *pButton)
{
    QRadioButton *pRadio = (QRadioButton*)pButton; // 클릭한 라디오 버튼

    // 라벨에 표시
    QString str = QString("clicked button: %1").arg(pRadio->text());
    ui->label->setText(str);
}

