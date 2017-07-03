#include "dialog.h"
#include <QApplication>
#include <QDebug>

class area
{
    friend class MyDialog;
private:
    int x;
    int y;
public:
    area()
    {

    }
    area(int x, int y) : x(x), y(y)
    {

    }
    void print()
    {
        qDebug() << this->x << " " << this->y;
    }
};

class MyDialog
{
    friend class area;
private:
    Dialog *p;
    int x;
    int y;
public:
    MyDialog(){}
    MyDialog(int a, int b) : x(a), y(b)
    {
        p = new Dialog;
        this->p->resize(this->x, this->y);
        this->p->show();
    }

    MyDialog(const area& ar)//constructor function
    {
        this->x = ar.x;
        this->y = ar.y;
        p = new Dialog;
        this->p->resize(this->x, this->y);
        this->p->show();
    }


    void operator =(const area& ar)//conversion operator
    {
        this->x = ar.x;
        this->y = ar.y;
        p = new Dialog;
        this->p->resize(this->x, this->y);
        this->p->show();
    }


    operator area()//class-type conversion function
    {
        area temp;
        temp.x = this->x;
        temp.y = this->y;
        return temp;
    }
};




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MyDialog w(200, 300);
    area a1;
    // MyDialog m(a1);

    // MyDialog m2;
    // m2 = a1;
    MyDialog m(250, 400);
    a1 = m;
    a1.print();

    return a.exec();
}
