// DOM(Document Object Model)
/*
 * QDomNodeList, QDomNode, QDomElement
 * DOM은 XML을 메모리에 모두 올려서 사용함
 */


#include <QCoreApplication>

#include <QtXml>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDomDocument doc;

    QFile file(":/read_sample.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "file open error";
        return -1;
    }

    if (!doc.setContent(&file))
    {
        qDebug() << "document open error";
        file.close();
        return -1;
    }

    QDomElement root = doc.firstChildElement();
    QDomNodeList nodeList = root.elementsByTagName("tag_type1");

    qDebug() << "node count: " << nodeList.count();
    for (int i = 0 ; i < nodeList.count() ; i++)
    {
        QDomNode node = nodeList.at(i);
        if (node.isElement())
        {
            QDomElement element = node.toElement();
            QString text = element.text();
            qDebug() << "name: " << element.attribute("name") << ", text: " << text;
        }
    }

    return a.exec();
}
