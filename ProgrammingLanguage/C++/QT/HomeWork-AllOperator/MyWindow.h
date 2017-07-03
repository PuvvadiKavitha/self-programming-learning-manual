#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <mainwindow.h>
#include <QDebug>
#define MAXSIZE 100
class MyWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow *m;
    int x;
    int y;
    int n;
    static int window_size;
    explicit MyWindow(QWidget *parent = 0);
    MyWindow(int x, int y);
    MyWindow(int n);
    ~MyWindow();
    void flash();
    MyWindow* operator +(const MyWindow& my);
    MyWindow* operator -(const MyWindow& my);
    MyWindow* operator *(const MyWindow& my);
    MyWindow* operator /(const MyWindow& my);
    MyWindow* operator %(const MyWindow& my);
    MyWindow* operator =(const MyWindow& my);

    MyWindow* operator +=(const MyWindow& my);
    MyWindow* operator -=(const MyWindow& my);
    MyWindow* operator *=(const MyWindow& my);
    MyWindow* operator /=(const MyWindow& my);
    MyWindow* operator %=(const MyWindow& my);

    MyWindow* operator ++();//head
    MyWindow* operator ++(int);//back
    MyWindow* operator --();
    MyWindow* operator --(int);

    bool operator >(const MyWindow& my);
    bool operator <(const MyWindow& my);
    bool operator >=(const MyWindow& my);
    bool operator <=(const MyWindow& my);
    bool operator ==(const MyWindow& my);
    bool operator !=(const MyWindow& my);

    MainWindow* operator [](int i);
    MainWindow* operator ()(int i);
    MainWindow* operator ->();
    MainWindow* operator *();

    bool operator &&(const MyWindow& my);
    bool operator ||(const MyWindow& my);
    bool operator !();

    MyWindow* operator &(const MyWindow& my);
    MyWindow* operator |(const MyWindow& my);
    MyWindow* operator ^(const MyWindow& my);
    MyWindow* operator ~();

    MyWindow* operator &=(const MyWindow& my);
    MyWindow* operator |=(const MyWindow& my);
    MyWindow* operator ^=(const MyWindow& my);
#if 1
    void* operator new(size_t size);
    void operator delete(void* p);
#endif

#if 1
    void* operator new[](size_t size);
    void operator delete[](void* p);
#endif
    /* 重载new和delete没做，重载流<< >>在VS中测试*/
/*
 * 声明为友元
 * friend istream & operator >>(istream &, complex & com);
   friend ostream & operator << (ostream &, const complex & com);
 *IO重载必须为非成员函数，必须声明为friend
istream & operator >>(istream &, complex & com)
{
    return cin >> com.x >> com.y;
}

ostream & operator << (ostream &, const complex & com)
{
    return  cout << com.x << "+" << com.y << "i" << endl;
}
 */

signals:

public slots:

};

#endif // MYWINDOW_H
