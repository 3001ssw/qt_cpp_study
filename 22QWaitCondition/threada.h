#ifndef THREADA_H
#define THREADA_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>

class ThreadA : public QThread
{
    Q_OBJECT
public:
    explicit ThreadA(QObject *parent = nullptr);

protected:
    virtual void run();
};

#endif // THREADA_H
