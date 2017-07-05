#include "MyApplication.h"
#include <QDebug>
#include <QEvent>


bool MyApplication::notify(QObject *obj, QEvent *ev)//使用app的notify函数来接收消息
{
    if (this->topLevelWidgets().count() > 0)
    {
        QWidget *mainwid = this->topLevelWidgets().at(0);
        if (obj == (QObject *)mainwid && (ev->type() == QEvent::MouseButtonPress))
        {
            qDebug() << "main window is clicked";
        }
    }
    return QApplication::notify(obj, ev);
}
