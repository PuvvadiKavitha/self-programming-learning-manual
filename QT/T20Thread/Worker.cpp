#include "Worker.h"

Worker::Worker(QObject *parent) :
    QObject(parent)
{
    //模板代码，必须会
    //将worker对象添加到thread线程中，该程序即变成多线程执行
    this->moveToThread(&this->thread);
    //Thread start
    this->thread.start();
    //线程退出的处理方式
    connect(&this->thread, SIGNAL(finished()),
            this, SLOT(deleteLater()));
}
