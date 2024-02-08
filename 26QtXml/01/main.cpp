// SAX(Simple API For XML)
/*
 * QXmlStreamReader, QXmlStreamWriter
 * XML 파일이 총 10줄일 경우 맨 윗줄 부터 한줄씩 읽으면서 메모리를 해제함
 * DOM 방식에 비해 속도가 빠르고 메모리를 덜 차지함
 */

#include <QCoreApplication>

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>

void readXML(QFile *file)
{
    QXmlStreamReader reader(file);
    if (reader.readNextStartElement())
    {
        if (reader.name().toString() == "tag")
        {
            while (reader.readNextStartElement())
            {
                if (reader.name().toString() == "tag_type1")
                {
                    QString nameStr = reader.attributes().value("name").toString();
                    int number = reader.readElementText().toInt();
                    qDebug() << "name: " << nameStr << ", no: " << number;
                }
            }
        }
    }
}

void writeXML()
{
    QByteArray data;
    QXmlStreamWriter writer(&data);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    {
        writer.writeStartElement("tag");
        {
            writer.writeStartElement("tag1");
            {
                writer.writeAttribute("name", "one");
                writer.writeCharacters("1");
            }
            writer.writeEndElement();

            writer.writeStartElement("tag2");
            {
                writer.writeAttribute("name", "two");
                writer.writeCharacters("2");
            }
            writer.writeEndElement();
        }
        writer.writeEndElement();
    }
    writer.writeEndDocument();

    QFile file("./write_sample.xml");

    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.write(data.data());
    file.close();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file(":/read_sample.xml");
    file.open(QFile::ReadOnly | QFile::Text);
    readXML(&file);
    file.close();


    writeXML();

    return a.exec();
}
