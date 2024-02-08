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
    int m_count;

public:
    void stop();
    void setCountPlus();

private:
    virtual void run();

signals:
    void signal_message(QString msg);
};

#endif // MYTHREAD_H
