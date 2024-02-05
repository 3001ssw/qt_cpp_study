#include "widget.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator trans;
    if (trans.load(":/trans/korean.qm"))
    {
        QApplication::installTranslator(&trans);
    }

    Widget w;
    w.show();
    return a.exec();
}
