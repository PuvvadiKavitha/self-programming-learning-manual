#include "MyWidget.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlDatabase>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{

#if 0
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
#endif

    //Qt封装了更加高级的数据库操作，这种原始的就不使用了
    //insert
    //db.exec("insert into tuser(username, password, gender)values('chengzhi01', '12345', 0)");
#if 0
    //query
    //QSqlQuery query = db.exec("select * from tuser");

    //int size = query.size();
    bool b = query.first();
    while (b)
    {
        QSqlResult* res = query.result();
        QVector<QVariant> v = res->boundValue();
        qDebug() << v;
        b = query.next();
    }
#endif
    //Qt的数据库API
    // QSqlTableModel: 数据表对应的数据结构
    QSqlTableModel model;
    model.setTable("tuser");
#if 1
    //insert
    QSqlRecord rec = model.record();//获得记录
    rec.setValue("username", "newuser");
    rec.setValue("password", "123456");
    rec.setValue("gender", 1);
    model.insertRecord(-1, rec);//-1代表最后一行
    model.submitAll();//全部提交
#endif

#if 0
    //updata  index(0, 1) 0行1列的数据
    model.setData(model.index(0, 1), "chengzhixxxx");
    model.submitAll();
#endif

#if 0
    //select
    //查询过滤器
    //model.setFilter("id = 1");
    //model.setFilter("username = 'chengzhi01'");
    model.setFilter("username != 'chengzhi'");//不等于使用<> 或者 !=
    model.select();
    int rowCount = model.rowCount();
    for (int i = 0; i != rowCount; i++)
    {
        QSqlRecord record = model.record(i);
        for (int j = 0; j != record.count(); j++)
        {
            qDebug() << record.value(j);
        } 
    }
#endif






}
