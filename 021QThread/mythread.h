#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QMutex>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

protected:
    int m_iCount;
    QMutex m_mutex;
public:
    int GetCount();

private:
    virtual void run();
};

#endif // MYTHREAD_H
