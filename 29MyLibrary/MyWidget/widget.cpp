#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myLib = new MyLibrary();

    connect(ui->pbtSum, SIGNAL(clicked()), this, SLOT(slot_buttonResultClicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_buttonResultClicked()
{
    quint32 iX = ui->leX->text().toInt();
    quint32 iY = ui->leY->text().toInt();

    quint32 iResult = myLib->getSum(iX, iY);
    ui->leResult->setText(QString("%1").arg(iResult));
}

