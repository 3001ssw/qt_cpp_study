// SAX(Simple API For XML)
/*
 * QXmlStreamReader, QXmlStreamWriter
 * XML 파일이 총 10줄일 경우 맨 윗줄 부터 한줄씩 읽으면서 메모리를 해제함
 * DOM 방식에 비해 속도가 빠르고 메모리를 덜 차지함
 */

// DOM(Document Object Model)
/*
 * QDomNodeList, QDomNode, QDomElement
 * DOM은 XML을 메모리에 모두 올려서 사용함
 */

#include <QCoreApplication>

#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>

void simpleReadXML(QFile *file)
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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file(":/sample.xml");
    file.open(QFile::ReadOnly | QFile::Text);
    simpleReadXML(&file);

    return a.exec();
}
