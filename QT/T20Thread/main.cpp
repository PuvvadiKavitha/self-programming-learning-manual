#include <QApplication>


#include "MyThread.h"
#include "Worker.h"
#include <QTimer>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);


#if 0
    MyThread _thread;
    _thread.foo();
    _thread.start();
    qDebug() << "Main:" << QThread::currentThread();
#endif
    qDebug() << "Main:" << QThread::currentThread();
    //不可指定父对象来管理线程对象
    //QObject::moveToThread: Cannot move objects with a parent
    //有父对象的线程对象不能被加到线程中，即不能指定父对象来管理线程对象的删除
    //Worker* _w = new Worker(&app);

    Worker* _w = new Worker;
    QTimer* _t = new QTimer;
    QObject::connect(_t, SIGNAL(timeout()),
                     _w, SLOT(doWork()));
    _t->setInterval(1000);
    _t->start();


    return app.exec();
}
