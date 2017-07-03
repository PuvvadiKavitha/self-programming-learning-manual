#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <stdlib.h>

class MyClass
{
private:
    MainWindow *m;
public:
    static int num;
    MyClass()
    {
        num += 1;
        qDebug() << MyClass::num;
        m = new MainWindow;
        m->resize(300, 300);
        m->show();

    }
    ~MyClass()
    {
        num -= 1;
        qDebug() << MyClass::num;
        delete m;
    }

    static void notepad()
    {
        system("notepad");
    }


};

int MyClass::num = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClass m;
    //MyClass::notepad();
    MyClass *p = NULL;
    p->notepad();
    //delete []m;
    //qDebug() << MyClass::num;

    return a.exec();
}
