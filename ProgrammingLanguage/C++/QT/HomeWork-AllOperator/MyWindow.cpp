#include "MyWindow.h"

int MyWindow::window_size = 0;

MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->m = new MainWindow;
    this->x = 200;
    this->y = 200;
    this->flash();
}
MyWindow::~MyWindow()
{
    delete m;
}

MyWindow::MyWindow(int n) : n(n)
{
    this->m = new MainWindow[this->n];
    for (int i = 0; i != this->n; i++)
    {
        this->m[i].resize(200, 200);
        this->m[i].move(200 * i, 0);
        this->m[i].show();
    }

}

MyWindow::MyWindow(int x, int y) : x(x), y(y), n(1)
{
    this->m = new MainWindow;
    this->m->resize(this->x, this->y);
    //this->m->show();
}

void MyWindow::flash()
{
    this->m->resize(this->x, this->y);
}

#if 0

void *operator new(size_t size)//对全局new的重载
{
    if (0 == size)
    {
        return 0;
    }
    void *p = malloc(sizeof(size));
    qDebug() << "全局new被调用，内存被分配";
    return p;
}

void operator delete(void *p)//对全局delete的重载
{
    qDebug() << "全局delete被调用，内存被回收";

    free(p);
}

void *operator new[](size_t size)
{

    qDebug() << "全局数组new被调用，内存即将被分配";
    return operator new(size);

}

void operator delete[](void *p)
{
    qDebug() << "全局数组delete被调用，内存即将被回收";
    return operator delete(p);
}
#endif



#if 1
//重载new和delete有问题
void* MyWindow::operator new(size_t size)
{
    window_size++;
    qDebug() << "New:Now window size = "<< window_size;
    MyWindow* p = ::new MyWindow;
    return p;
}

void MyWindow::operator delete(void* p)
{
    window_size--;
    qDebug() << "Delete:Now window size = "<< window_size;
    ::delete p;
}
#endif


#if 1
void* MyWindow::operator new[](size_t size)
{
    qDebug() << "New[]:Now window size = "<< window_size;
    return operator new(size);
}

void MyWindow::operator delete[](void* p)
{
    qDebug() << "Delete:Now window size = "<< window_size;
    return operator delete(p);
}

#endif

MyWindow* MyWindow::operator +(const MyWindow& my)
{
    MyWindow* ptemp = new MyWindow(0, 0);
    ptemp->x = this->x + my.x;
    ptemp->y = this->y + my.y;
    //ptemp->m->resize(ptemp->x, ptemp->y);
    ptemp->flash();
    return ptemp;
}


MyWindow* MyWindow::operator =(const MyWindow& my)
{

    this->m = new MainWindow;
    this->x = my.x;
    this->y = my.y;
    this->flash();
    return this;

}

MyWindow* MyWindow::operator -(const MyWindow& my)
{
    MyWindow* ptemp = new MyWindow(0, 0);
    ptemp->x = this->x - my.x;
    ptemp->y = this->y - my.y;
    ptemp->flash();
    return ptemp;
}

MyWindow* MyWindow::operator *(const MyWindow& my)
{
    MyWindow* ptemp = new MyWindow(0, 0);
    ptemp->x = this->x * my.x;
    ptemp->y = this->y * my.y;
    ptemp->flash();
    return ptemp;
}

MyWindow* MyWindow::operator /(const MyWindow& my)
{
    MyWindow* ptemp = new MyWindow(0, 0);
    ptemp->x = this->x / my.x;
    ptemp->y = this->y / my.y;
    ptemp->flash();
    return ptemp;
}

MyWindow* MyWindow::operator %(const MyWindow& my)
{
    MyWindow* ptemp = new MyWindow(0, 0);
    ptemp->x = this->x % my.x;
    ptemp->y = this->y % my.y;
    ptemp->flash();
    return ptemp;
}

MyWindow* MyWindow::operator +=(const MyWindow& my)
{
    this->x += my.x;
    this->y += my.y;
    this->flash();
    return this;
}
MyWindow* MyWindow::operator -=(const MyWindow& my)
{
    this->x -= my.x;
    this->y -= my.y;
    this->flash();
    return this;
}
MyWindow* MyWindow::operator *=(const MyWindow& my)
{
    this->x *= my.x;
    this->y *= my.y;
    this->flash();
    return this;
}

MyWindow* MyWindow::operator /=(const MyWindow& my)
{
    this->x /= my.x;
    this->y /= my.y;
    this->flash();
    return this;
}

MyWindow* MyWindow::operator %=(const MyWindow& my)
{
    this->x %= my.x;
    this->y %= my.y;
    this->flash();
    return this;
}


MyWindow* MyWindow::operator ++()
{
    this->x += 100;
    this->y += 100;
    this->flash();
    return this;
}
MyWindow* MyWindow::operator ++(int)
{
    MyWindow* ptemp = new MyWindow(0, 0);
    ptemp->x = this->x;
    ptemp->y = this->y;
    ptemp->flash();

    this->x += 100;
    this->y += 100;
    this->flash();
    return ptemp;
}


MyWindow* MyWindow::operator --()
{
    this->x -= 100;
    this->y -= 100;
    this->flash();
    return this;
}

MyWindow* MyWindow::operator --(int)
{
    MyWindow* ptemp = new MyWindow(0, 0);
    ptemp->x = this->x;
    ptemp->y = this->y;
    ptemp->flash();

    this->x -= 100;
    this->y -= 100;
    this->flash();
    return ptemp;
}


bool MyWindow::operator >(const MyWindow& my)
{
    return (this->x > my.x) && (this->y > my.y);
}

bool MyWindow::operator <(const MyWindow& my)
{
    return (this->x < my.x) && (this->y < my.y);
}

bool MyWindow::operator >=(const MyWindow& my)
{
    return (this->x >= my.x) && (this->y >= my.y);
}

bool MyWindow::operator <=(const MyWindow& my)
{
    return (this->x <= my.x) && (this->y <= my.y);
}

bool MyWindow::operator ==(const MyWindow& my)
{
    return (this->x == my.x) && (this->y == my.y);
}


bool MyWindow::operator !=(const MyWindow& my)
{
    return (this->x != my.x) && (this->y != my.y);
}


MainWindow* MyWindow::operator [](const int i)
{
    if (i < 0 || i >= n)
    {
        qDebug() << "Index out of range";
        return nullptr;
    }
    return &(this->m[i]);
}

MainWindow* MyWindow::operator ()(const int i)
{
    if (i < 0 || i >= n)
    {
        qDebug() << "Index out of range";
        return nullptr;
    }
    return &(this->m[i]);
}

MainWindow* MyWindow::operator ->()
{
    return (this->m);
}

MainWindow* MyWindow::operator *()
{
    return (this->m);
}

bool MyWindow::operator &&(const MyWindow& my)
{
    return ((this->x > MAXSIZE) && (this->y > MAXSIZE)) && ((my.x > MAXSIZE) && (my.y > MAXSIZE));
}

bool MyWindow::operator ||(const MyWindow& my)
{
    return ((this->x > MAXSIZE) && (this->y > MAXSIZE)) || ((my.x > MAXSIZE) && (my.y > MAXSIZE));
}

bool MyWindow::operator !()
{
    return !((this->x > MAXSIZE) && (this->y > MAXSIZE));
}


MyWindow* MyWindow::operator &(const MyWindow& my)
{
    MyWindow* ptemp = new MyWindow(0, 0);
    ptemp->x = this->x & my.x;
    ptemp->y = this->y & my.y;
    ptemp->flash();
    return ptemp;
}

MyWindow* MyWindow::operator |(const MyWindow& my)
{
    MyWindow* ptemp = new MyWindow(0, 0);
    ptemp->x = this->x | my.x;
    ptemp->y = this->y | my.y;
    ptemp->flash();
    return ptemp;
}


MyWindow* MyWindow::operator ^(const MyWindow& my)
{
    MyWindow* ptemp = new MyWindow(0, 0);
    ptemp->x = this->x ^ my.x;
    ptemp->y = this->y ^ my.y;
    ptemp->flash();
    return ptemp;
}

MyWindow* MyWindow::operator ~()
{
    this->x = ~(this->x);
    this->y = ~(this->y);
    this->flash();
    return this;
}


MyWindow* MyWindow::operator &=(const MyWindow& my)
{
    this->x &= my.x;
    this->y &= my.y;
    this->flash();
    return this;
}

MyWindow* MyWindow::operator |=(const MyWindow& my)
{
    this->x |= my.x;
    this->y |= my.y;
    this->flash();
    return this;
}


MyWindow* MyWindow::operator ^=(const MyWindow& my)
{
    this->x ^= my.x;
    this->y ^= my.y;
    this->flash();
    return this;
}






