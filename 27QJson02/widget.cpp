#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::slot_buttonParsing);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_buttonParsing()
{
    qDebug() << Q_FUNC_INFO;
    ui->textEdit->clear();

    QFile file(":/sample.json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text) == false)
    {
        ui->textEdit->setText("open failed");
        return;
    }

    QString data = file.readAll();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toLocal8Bit());

    QJsonObject jsonObj = jsonDoc.object();

    QString dateStr = jsonObj["date"].toString();
    QString timeStr = jsonObj["time"].toString();

    ui->textEdit->append(dateStr);
    ui->textEdit->append(timeStr);

    QJsonArray jsonArray = jsonObj["work"].toArray();
    foreach(const QJsonValue& value, jsonArray)
    {
        QJsonObject obj = value.toObject();
        int id = obj["id"].toInt();
        QString do_job = obj["do_job"].toString();

        QString arrayString = QString("id: %1, do job: %2").arg(id).arg(do_job);
        ui->textEdit->append(arrayString);
    }

}

