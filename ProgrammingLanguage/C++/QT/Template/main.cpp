#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QDialog>


//类模板
template <typename T>
class Show
{
public:
    T* p;
    Show()
    {
        p = new T;
        p->show();
    }
};

//模板可以让类与数据类型无关，泛型的概念
//多态，一个接口，可以无限拓展，实现软件的可定制可拓展
template <typename T>//抽象类模板
class MyWindow
{
public:
    T* p;
    virtual void show() = 0;
};

class MyButton : public MyWindow<QPushButton>
{
public:
    MyButton()
    {
        this->p = new QPushButton;
    }
    ~MyButton()
    {
        delete this->p;
    }
    void show()
    {
        p->show();
    }
};

class MyQLabel : public MyWindow<QLabel>
{
public:
    MyQLabel()
    {
        this->p = new QLabel;
    }
    ~MyQLabel()
    {
        delete this->p;
    }
    void show()
    {
        p->show();
    }
};

template <typename T>
class MyNewWindow  : public MyWindow<T>
{
public:
    MyNewWindow()
    {
        this->p = new T;
    }
    ~MyNewWindow()
    {
        delete this->p;
    }
    void show()
    {
        this->p->show();
    }
};


#if 0
template <typename T>
class mywindow
{
   template <typename T> friend void run(mywindow<T> &d);
private:
    T *p;
    void show()
    {
       p->show();
    }


public:
    mywindow()
    {
       p = new T;
    }

};

template <typename T>
void run( mywindow <T> &d)
{
    d.show();
}

#endif


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if 0
    mywindow<QDialog> my;
    run(my);
#endif


#if 0
    MyWindow<QLabel>* p = new MyNewWindow<QLabel>;
    p->show();
#endif

#if 0
    MyWindow<QLabel>* p1 = new MyQLabel;
    p1->show();
    MyWindow<QPushButton>* p = new MyButton;
    p->show();
#endif

#if 0
    Show<MainWindow> s1;
    Show<QLabel> s2;
    Show<QPushButton> s3;
#endif
    return a.exec();
}
