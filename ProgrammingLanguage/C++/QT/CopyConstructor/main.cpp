#include "mainwindow.h"
#include <QApplication>

class MyWindow
{
public:
    MainWindow *p;
    MyWindow()
    {
        p = new MainWindow[3];
        for (int i = 0; i != 3; i++)
        {
            p[i].resize(200, 200);
            p[i].move(i * 100, i * 100);
            p[i].show();
        }
    }
    MyWindow(const MyWindow &my)
    {
        //this->p = my.p;//浅拷贝
        this->p = new MainWindow[3];//深拷贝
        for (int i = 0; i != 3; i++)
        {
            p[i].resize(500, 500);
            p[i].move(i * 300, i * 300);
            p[i].show();
        }
    }

    ~MyWindow()
    {
        delete []p;
    }

};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWindow w;
    MyWindow w1(w);
    //w.show();

    return a.exec();
}
