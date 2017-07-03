#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

class MyClass
{
    friend void my_show(MyClass &m); //友元函数,可以访问本类的私有变量
    friend class RunClass;			//友元类,可以访问本类的私有变量
public:
    MyClass()
    {
        qDebug() << "MyClass";
    }
    ~MyClass()
    {
        qDebug() << "~MyClass";
    }

private:
    MainWindow *p;
    int x;
    int y;
};


class RunClass
{
public:
    MyClass m;
    RunClass()
    {
        qDebug() << "RunClass";
        m.p = new MainWindow;
        m.x = 500;
        m.y = 500;
        m.p->resize(m.x, m.y);
        m.p->show();
    }
    ~RunClass()
    {
        qDebug() << "~RunClass";
    }

};



void my_show(MyClass &m)
{
    m.p = new MainWindow();
    m.p->show();
}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MyClass m;
    //my_show(m);

    RunClass();//temp
    //RunClass r = RunClass();

    return a.exec();
}
