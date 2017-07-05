#include <QCoreApplication>
#include "MySignal.h"
#include "MySlot.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    MySignal sig;
    MySlot myslot;
    QObject::connect(&sig, SIGNAL(my_signal()), &myslot, SLOT(my_slot()));
    emit sig.my_signal();//发送信号

    return app.exec();
}

