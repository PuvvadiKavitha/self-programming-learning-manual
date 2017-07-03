#include "mainwindow.h"
#include <QApplication>
#include "MyWindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWindow* p = new MyWindow;
    //p->m->show();
    delete p;

#if 0
    MyWindow m1(300, 400);
    MyWindow m2(500, 600);
    m2.m->show();

    m1 ^= m2;
    qDebug() << m1.m->width() << " " << m1.m->height();
    m1.m->show();
#endif

#if 0
    MyWindow m1(300, 400);
    MyWindow m2(500, 600);
    m2.m->show();

    m1 |= m2;
    qDebug() << m1.m->width() << " " << m1.m->height();
    m1.m->show();
#endif

#if 0
    MyWindow m1(300, 400);
    MyWindow m2(500, 600);
    m2.m->show();

    m1 &= m2;
    qDebug() << m1.m->width() << " " << m1.m->height();
    m1.m->show();
#endif




#if 0
    MyWindow m1(500, 700);
    m1.m->show();
    MyWindow* m3 = new MyWindow(0, 0);
    m3 = ~m1;
    qDebug() << m3->m->width() << " " << m3->m->height();
    m3->m->show();
#endif



#if 0
    MyWindow m1(300, 400);
    MyWindow m2(500, 600);
    m1.m->show();
    m2.m->show();
    MyWindow* m3 = new MyWindow(0, 0);
    m3 = m1 ^ m2;
    qDebug() << m3->m->width() << " " << m3->m->height();
    m3->m->show();
#endif



#if 0
    MyWindow m1(300, 400);
    MyWindow m2(500, 600);
    m1.m->show();
    m2.m->show();
    MyWindow* m3 = new MyWindow(0, 0);
    m3 = m1 | m2;
    qDebug() << m3->m->width() << " " << m3->m->height();
    m3->m->show();
#endif



#if 0
    MyWindow m1(300, 400);
    MyWindow m2(500, 600);
    m1.m->show();
    m2.m->show();
    MyWindow* m3 = new MyWindow(0, 0);
    m3 = m1 & m2;
    qDebug() << m3->m->width() << " " << m3->m->height();
    m3->m->show();
#endif


#if 0
    MyWindow m1(300, 400);
    MyWindow m2(99, 99);
    m1.m->show();
    m2.m->show();
    qDebug() << (m1 && m2);
    qDebug() << (m1 || m2);
    qDebug() << (!m1);
    qDebug() << (!m2);

#endif





#if 0
    MyWindow m(5);

    MyWindow* m1 = new MyWindow(5);
    (*m1)->hide();//运算符重载只作用类的对象，不作用与类本身和指针

    m[1]->hide();
    m(2)->hide();
    (*m + 3)->hide();
#endif



#if 0
    MyWindow m1(400, 600);
    m1.m->show();
    MyWindow m2(300, 400);
    m2.m->show();
    qDebug() << (m1 > m2);
    qDebug() << (m1 < m2);
    qDebug() << (m1 >= m2);
    qDebug() << (m1 <= m2);
    qDebug() << (m1 == m2);
    qDebug() << (m1 != m2);


#endif





#if 0
    MyWindow m1(300, 400);
    MyWindow* m2 = m1--;
    m1.m->show();
    m2->m->show();

#endif

#if 0
    MyWindow m1(300, 600);
    MyWindow* m2 = m1++;
    m1.m->show();
    m2->m->show();

#endif




#if 0
    MyWindow m1(300, 600);
    --m1;
    m1.m->show();

#endif

#if 0
    MyWindow m1(300, 600);
    //++m1;
    m1.m->show();

#endif



#if 0
    MyWindow m1(300, 600);
    //m1.m->show();
    MyWindow m2(7, 7);
    m2.m->show();

    m1 %= m2;
    m1.m->show();

#endif


#if 0
    MyWindow m1(300, 600);
    //m1.m->show();
    MyWindow m2(3, 6);
    m2.m->show();

    m1 /= m2;
    m1.m->show();

#endif

#if 0
    MyWindow m1(40, 60);
    //m1.m->show();
    MyWindow m2(30, 40);
    m2.m->show();

    m1 *= m2;
    m1.m->show();

#endif




#if 0
    MyWindow m1(400, 600);
    //m1.m->show();
    MyWindow m2(300, 400);
    m2.m->show();

    m1 -= m2;
    m1.m->show();

#endif

#if 0
    MyWindow m1(400, 600);
    m1.m->show();
    MyWindow m2(100, 100);
    //m2.m->show();
    m2 += m1;
    m2.m->show();


#endif

#if 0
    MyWindow m1(400, 600);
    m1.m->show();
    MyWindow m2(40, 60);
    m2.m->show();

    MyWindow *m3 = new MyWindow(0, 0);
    m3 = m1 % m2;
    m3->m->show();
#endif

#if 0
    MyWindow m1(400, 600);
    m1.m->show();
    MyWindow m2(40, 60);
    m2.m->show();

    MyWindow *m3 = new MyWindow(0, 0);
    m3 = m1 / m2;
    m3->m->show();
#endif



#if 0
    MyWindow m1(100, 100);
    m1.m->show();
    MyWindow m2(30, 20);
    m2.m->show();

    MyWindow *m3 = new MyWindow(0, 0);
    m3 = m1 * m2;
    m3->m->show();
#endif

#if 0
    MyWindow m1(100, 100);
    m1.m->show();
    MyWindow m2(30, 20);
    m2.m->show();

    MyWindow *m3 = new MyWindow(0, 0);
    m3 = m1 * m2;
    m3->m->show();
#endif


#if 0
    MyWindow *m3 = new MyWindow(0, 0);
    m3 = m1 - m2;
    m3->m->show();
#endif





#if 0
    MyWindow m3;
    m3 = m1;
    //MyWindow* m4 = new MyWindow(0, 0);
    //m4 = (m3 = m1);
    //m4->m->show();
    //(m3 = m1)->m->show();
    m3.m->show();
#endif




#if 0
    MyWindow *m3 = new MyWindow(0, 0);
    m3 = m1 + m2;
    m3->m->show();
#endif



    return a.exec();
}
