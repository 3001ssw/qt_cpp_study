#ifndef REMOTECTRL_H
#define REMOTECTRL_H

#include <QObject>

class RemoteCtrl : public QObject
{
    Q_OBJECT
public:
    explicit RemoteCtrl(QObject *parent = nullptr);

    void clickTvOnButton();

signals:
    void signal_TvOn();

};

#endif // REMOTECTRL_H
