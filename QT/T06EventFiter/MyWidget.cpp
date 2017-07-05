#include "MyWidget.h"
#include <MyApplication.h>
#include <QEvent>
#include <QDebug>
#include <QApplication>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    QPushButton *button;
    button = new QPushButton("Exit", this);
    _button = button;
    connect(button, SIGNAL(clicked()), this, SLOT(close()));
    button->installEventFilter(this);//事件的过滤器

}

bool MyWidget::eventFilter(QObject *obj, QEvent *ev)
{
    if (obj == (QObject *)_button && (
                ev->type() == QEvent::MouseButtonPress ||
                ev->type() == QEvent::MouseButtonRelease ||
                ev->type() == QEvent::MouseButtonDblClick))
    {
        qDebug() << "Exit的事件被过滤";
        return true;
    }
    return QWidget::eventFilter(obj, ev);
}

bool MyWidget::event(QEvent *ev)
{
    if (ev->type() == QEvent::User)
    {
        qDebug() << "User Event is comming";//组件之间通信
    }
}

int main(int argc, char **argv)
{
    MyApplication app(argc, argv);
    MyWidget w;
    w.show();
    qDebug() << "begin";
    //app.sendEvent(&w, new QEvent(QEvent::User));//等待发送的消息的接收才返回，同步执行，立即处理
    //建议使用postEvent
    //app.postEvent(&w, new QEvent(QEvent::User));//发一个消息到消息队列中就返回，异步执行，等待处理
    qDebug() << "end";
    return app.exec();
}
