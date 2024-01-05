#include "Tv.h"
#include <QDebug>

Tv::Tv(QObject *parent)
    : QObject{parent}
{}

void Tv::slot_TvOn()
{
    qDebug() << "Do Tv On";
}
