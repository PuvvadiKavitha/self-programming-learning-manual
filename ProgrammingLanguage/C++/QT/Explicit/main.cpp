#include "mainwindow.h"
#include <QApplication>


class MyWindowSize
{
public:
    int width;
    int height;
    MyWindowSize(int x, int y):width(x), height(y)
    {

    }
    ~MyWindowSize()
    {

    }
};


class MyClass
{
public:
    MainWindow m;
    int x;
    int y;
public:
    MyClass(int num) : x(num), y(num)
    {
        m.resize(x, y);
        m.show();
    }
    //explicit 禁用一些隐式转换
    explicit MyClass(const MyWindowSize &size)
    {
        x = size.width;
        y = size.height;
        m.resize(x, y);
        m.show();
    }

    ~MyClass()
    {

    }


};







int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MyClass m(500);
    //MyClass m = 500;
    MyWindowSize size(300, 500);
    //MyClass m(size);//隐式转换
    //MyClass m = (MyClass)size;//显式转换
    //MyClass m = MyClass(size);//调用构造函数转换
    //MyClass m = size;//调用构造函数转换






    return a.exec();
}
