#include "widget.h"
#include "ui_widget.h"

#include <QHBoxLayout>
#include <QDebug>

#include "ImageButton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ImageButton *imgButton1 = new ImageButton(this);
    ImageButton *imgButton2 = new ImageButton(this);

    QHBoxLayout *hlayout = new QHBoxLayout(this);
    hlayout->addWidget(imgButton1);
    hlayout->addWidget(imgButton2);

    setLayout(hlayout);

    connect(imgButton1, SIGNAL(mouseHovering()), this, SLOT(slot_hovering()));
    connect(imgButton1, &ImageButton::mouseClciked, this, &Widget::slot_clicked);

    imgButton2->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_hovering()
{

}

void Widget::slot_clicked()
{

}

