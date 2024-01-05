#include "RemoteCtrl.h"
#include <QDebug>

RemoteCtrl::RemoteCtrl(QObject *parent)
    : QObject{parent}
{

}

void RemoteCtrl::clickTvOnButton()
{
    qDebug() << "Click Tv On Button";

    emit signal_TvOn();
}
