#include "MySlot.h"
#include <QDebug>
MySlot::MySlot(QObject *parent) :
    QObject(parent)
{
}


void MySlot::my_slot()
{
    qDebug() << "my_signal is comming";
}
