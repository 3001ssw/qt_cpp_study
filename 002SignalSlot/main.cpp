#include <QCoreApplication>
#include "RemoteCtrl.h"
#include "Tv.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RemoteCtrl *pRmc = new RemoteCtrl;
    Tv *pTv = new Tv;

    QObject::connect(pRmc, SIGNAL(signal_TvOn()), pTv, SLOT(slot_TvOn()));

    pRmc->clickTvOnButton();

    return a.exec();
}
