#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>



class Interface//指针接口
{
public:
    virtual void my_show() = 0;//函数接口
};

class MyWindow : public Interface
{
public:
    MainWindow* p;
    MyWindow()
    {
        p = new MainWindow;
    }
    void my_show()
    {
        p->show();
    }

};

class MyButton : public Interface
{
public:
    QPushButton* p;
    MyButton()
    {
        p = new QPushButton;
    }
    void my_show()
    {
        p->show();
    }

};





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Interface* p = new MyWindow;
    p->my_show();
    Interface* p2 = new MyButton;
    p2->my_show();

    return a.exec();
}
