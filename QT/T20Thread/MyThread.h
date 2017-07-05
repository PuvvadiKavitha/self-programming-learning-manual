#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>
class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    void run() override
    {
        this->foo();
        qDebug() << "Thread is Run";
    }
    void foo()
    {
        qDebug() << QThread::currentThread();
    }



signals:

public slots:

};

#endif // MYTHREAD_H
