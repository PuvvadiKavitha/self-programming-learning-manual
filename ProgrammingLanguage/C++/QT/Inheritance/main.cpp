#include "mainwindow.h"
#include <QApplication>
#include <windows.h>
#include <stdlib.h>
#include <QLabel>
#include <QPushButton>
#include <QDialog>
#include <windows.h>

class MyWindow : public MainWindow//Inheritance:Is-A
{
public:
    MainWindow *p;//Has-A
    void show1(MainWindow& w)//Use-A
    {
        w.show();
    }
    void hide(MainWindow &w)
    {
        w.hide();
    }
    void sys(char* cmd)
    {
        system(cmd);
    }
    void smallToBig()
    {
        this->resize(100, 100);
        for (int i = 0; i < 800; i++)
        {
            this->resize(i, i);
        }
    }

protected:
    int x;
private:
    int y;
public:
    int z;
};

class NewMyWindow : public MyWindow
{
public:
    void leftToRight()
    {
        this->resize(100, 100);
        this->move(0, 0);
        for (int i = 0; i < 1000; i++)
        {
            this->move(i, 0);
        }
    }
};

class NewNewMyWindow : public NewMyWindow
{
public:
    void leftToRightAndSmallToBig()
    {
        this->resize(100, 100);
        this->move(0, 0);
        int i = 0;

        for (i = 0; i < 800; i++)
        {
            this->show();
            this->move(i, 0);
            this->resize(i, i);

        }
        for (i = 800; i >= 0; i--)
        {
            this->show();
            this->move(i, 0);
            this->resize(i, i);
        }
    }
};

//多继承
class girlboy : public QDialog, public  QLabel, public QPushButton
{
public:
    girlboy()
    {
        this->QDialog::show();
        this->QLabel::show();
        this->QPushButton::show();
        this->QDialog::setWindowTitle("hello world  i am boy");
        this->QLabel::setWindowTitle("hello world ,i am girl");
        this->QPushButton::setWindowTitle("i am not man");

    }
    void hide()
    {
       this->QDialog::hide();
       this->QLabel::hide();
    }

};

class Windx
{
protected:
    MainWindow* p;
public:
    Windx()
    {
        p = new MainWindow;
        p->show();
    }
};

class WindAx : virtual  public Windx
{
public:
    WindAx()
    {
        Sleep(2000);
        this->p->setWindowTitle("Ax");
    }
};

class WindBx : virtual public Windx
{
public:
    WindBx()
    {
        Sleep(2000);
        this->p->setWindowTitle("Bx");
    }
};

class WindCx : virtual public Windx
{
public:
    WindCx()
    {
        Sleep(2000);
        this->p->setWindowTitle("Cx");
    }
};

class WindDx : virtual public Windx
{
public:
    WindDx()
    {
        Sleep(2000);
        this->p->setWindowTitle("Dx");
    }
};
//虚继承的同一个类的子类共用一个虚基类对象，其他的非虚继承的子类独享一个父类对象
//a b c d 都虚继承windx 最后只有一个Dx窗口，四个子类共享虚基类对象
//a b c 虚继承windx而 d普通继承windx，最后有Cx和Dx两个窗口，adc共享虚基类并且设置最后一个虚继承的窗口的标题，而d独享了另一个windx
class WindAB : public WindAx, public WindBx, public WindCx, public WindDx
{

};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WindAB ab;

#if 0

    girlboy g;
    g.hide();
#endif



#if 0
    NewNewMyWindow* p = new NewNewMyWindow;
    //p->show();
    p->leftToRightAndSmallToBig();
    //p->smallToBig();
    //p->leftToRight();
#endif

#if 0
    MyWindow w;
    //w.x;保护成员外部不能访问-最持家
    //w.y;私有成员外部不能访问-最败家
    //w.z;公有成员外部可以访问-最热心
#endif


#if 0
    MainWindow w0;
    MyWindow w;
    Sleep(3000);
    w.show(w0);
    Sleep(3000);
    w.hide(w0);
    Sleep(3000);
    w.sys("tasklist & pause");
#endif
    return a.exec();
}
