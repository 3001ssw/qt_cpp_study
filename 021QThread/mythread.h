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
    bool m_bThreadStop;
    QMutex m_mutex;

public:
    void stop();

signals:
    void signal_count(int count);

private:
    virtual void run();

};

#endif // MYTHREAD_H
