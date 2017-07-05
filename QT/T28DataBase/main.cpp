#include "MyWidget04.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    //打开数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");//MYSQL的名称
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("872785786");
    db.setDatabaseName("d0718");//数据库名称
    bool ret = db.open();//打开
    if (ret == false)
    {
        qDebug() << "db open fail" << db.lastError().text();//错误信息
        exit(0);
    }
    qDebug() << "db open success";

    MyWidget04 w;
    w.show();
    return app.exec();
}
