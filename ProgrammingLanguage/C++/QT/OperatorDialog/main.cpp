#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setXY(400, 200);
    w.show();

    Dialog w2;
    w2.setXY(200, 400);
    w2.show();

    //Dialog* p1 = *(++w) + w2;
    //p1->show();

    Dialog* p2 = *(w++) + w2;
    p2->show();

    return a.exec();
}
