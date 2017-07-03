#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
class MyWindow
{
public:
    MainWindow *p;
    MainWindow *px;
    int n;
    int x;
    int y;
    MyWindow(){}
    MyWindow(int x, int y) : x(x), y(y)
    {
        p = new MainWindow;
        p->resize(this->x, this->y);
        p->show();
    }

    MyWindow(int n) : n(n)
    {
        p = new MainWindow[n];
        for (int i = 0; i != n; i++)
        {
            p[i].resize(100, 100);
            p[i].move(i * 100, 0);
            p[i].show();
        }
    }

    ~MyWindow()
    {
        delete p;
    }

    MyWindow(const MyWindow& my)
    {
        this->p = new MainWindow[this->n = my.n];//自己实现的深拷贝

        //系统自定义的浅拷贝
        //this->n = my.n;
        //this->p = my.p;
    }


#if 1
    //返回类的引用, 不会调用拷贝构造函数
    //不返回引用会调用拷贝构造函数
    MyWindow* operator =(const MyWindow& my)
    {
        this->p = new MainWindow[this->n = my.n];
        for (int i = 0; i != this->n; i++)
        {
            p[i].resize(100, 100);
            p[i].move(0, i * 100);
            p[i].show();
        }
        return this;
    }
#endif

    /*void operator =(const MyWindow& my)
    {
        this->p = new MainWindow[this->n = my.n];
        for (int i = 0; i != this->n; i++)
        {
            p[i].resize(100, 100);
            p[i].move(0, i * 100);
            p[i].show();
        }

    }*/


    bool operator >(const MyWindow &my)
    {
        return ((this->x) *  (this->y)) > (my.x * my.y);
    }

    bool operator >(const int x)
    {
        return this->x > x;
    }

    MainWindow* operator [](int i)
    {
        if (i < 0 || i >= n)
        {
            return nullptr;
        }
        return &(this->p[i]);
    }
    const MainWindow* operator [](const int i) const
    {
        if (i < 0 || i >= n)
        {
            return nullptr;
        }
        return &(this->p[i]);
    }

    MainWindow* operator ()(int i)
    {
        if (i < 0 || i >= n)
        {
            return nullptr;
        }
        return &(this->p[i]);
    }

    MainWindow* operator ()(int i, char* str)
    {
        if (i < 0 || i >= n)
        {
            return nullptr;
        }
        this->p[i].setWindowTitle(str);
        return &(this->p[i]);
    }

    MainWindow* operator *()//重载乘法有参数，指针没有参数
    {
        return this->p;
    }

    MainWindow* operator ->()
    {
        return this->p;
    }

    void print()
    {
        qDebug() << "MainWindow print";
    }
    void operator ^=(const MyWindow& my)
    {
        this->x ^= my.x;
        this->y ^= my.y;
    }
    void flash()
    {
        this->p->resize(this->x, this->y);
    }
};



class Fu
{
public:
    int money;
};

class Shuai
{
public:
    int handsome;
};

class gao
{
public:
    int height;
};


bool operator &&(const gao& g, const Shuai& s)
{
    return (g.height > 170) && (s.handsome > 90);
}

bool operator &&(bool res, const Fu& f)
{
    return (res && (f.money > 1000000));
}
//企业实战:两个类不借助第三个变量交换信息，需要亦或操作，并且不会越界
//四则运算会越界
MyWindow* operator ^(const MyWindow& my1, const MyWindow& my2)
{
    MyWindow* ptemp = new MyWindow(0, 0);
    ptemp->x = my1.x ^ my2.x;
    ptemp->y = my1.y ^ my2.y;
    ptemp->flash();
    return ptemp;
}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWindow m1(300, 600);
    m1.p->setWindowTitle("11111111111");
    MyWindow m2(600, 300);
    m2.p->setWindowTitle("22222222222");
    MyWindow* p = m1 ^ m2;
#if 0
    m1 ^= m2;
    m2 ^= m1;
    m1 ^= m2;
    m1.flash();
    m2.flash();
#endif
#if 0
     gao g;
     g.height = 180;
     Shuai s;
     s.handsome = 89;
     Fu f;
     f.money = 2000000;
     if (g && s && f)
     {
         QMessageBox::information(&m, "Fenjie", "JiaGeiNi");

     }
     else
     {
         QMessageBox::critical(&m, "Fenjie", "GunGUnGun");
     }
#endif


#if 0
    MyWindow my1(300, 300);
    MyWindow my2(400, 400);
    qDebug() << (my1 > my2);
    qDebug() << (my1.x > my2.x);
#endif
#if 0
    MyWindow my(5);//类型定义的时候是构造函数初始化
    //my(1, "1111")->show();//变量名前面没有类型，调用方法

    //重载作用于某个类的对象不作用域类型名
    //MyWindow->hide();
    //(*MyWindow)->hide();
    my->hide();//*********重载作用于某个类的对象不作用域类型名*********
    (*my + 2)->hide();

    //my[2]->hide();//隐藏第三个窗口
    //my(3)->hide();

#endif
#if 0
    MyWindow my(5);
    MyWindow my3;
    my3 = my;
    //qDebug() <<  (void*)((my3 = my).p) << (my3 = my).n;

    //MyWindow my2;
    // my2 = my;调用默认赋值重载，是浅拷贝
#endif




    return a.exec();
}
