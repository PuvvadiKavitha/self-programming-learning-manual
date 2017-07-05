#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>


class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    QThread thread;
    bool event(QEvent *ev) override//设置了自己对象的线程属性后，消息机制将被那个线程接管
    {
        qDebug() << "event" << QThread::currentThread();
        return QObject::event(ev);
    }

signals:

public slots:
    void doWork()
    {
        // do ......
        qDebug() << QThread::currentThread();
    }

};

#endif // WORKER_H
