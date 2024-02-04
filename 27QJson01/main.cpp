#include <QCoreApplication>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file(":/sample.json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text) == false)
    {
        qDebug() << "open failed";
        return -1;
    }

    QString data = file.readAll();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toLocal8Bit());

    QJsonObject jsonObj = jsonDoc.object();

    QString dateStr = jsonObj["date"].toString();
    QString timeStr = jsonObj["time"].toString();

    qDebug() << dateStr;
    qDebug() << timeStr;

    QJsonArray jsonArray = jsonObj["work"].toArray();
    foreach(const QJsonValue& value, jsonArray)
    {
        QJsonObject obj = value.toObject();
        int id = obj["id"].toInt();
        QString do_job = obj["do_job"].toString();

        QString arrayString = QString("id: %1, do job: %2").arg(id).arg(do_job);
        qDebug() << arrayString;
    }
    return a.exec();
}
