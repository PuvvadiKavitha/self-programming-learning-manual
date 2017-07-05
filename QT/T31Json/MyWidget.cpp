#include "MyWidget.h"
#include <QApplication>
#include <QJsonObject>//json对象
#include <QJsonDocument>//json文档，传输的时候是传输文档
#include <QDebug>
#include <QCryptographicHash>//加密


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    QJsonObject obj;
    //添加数据
    obj.insert("name", QString("chengzhi"));
    //密码md5加密
    QByteArray md5 = QCryptographicHash::hash(QByteArray("chengzhi"), QCryptographicHash::Md5);
    obj.insert("password", QString(md5.toHex()));

    obj.insert("male", true);
    obj.insert("age", 20);
    //写入json
    QJsonDocument doc(obj);
    //写入的Json格式
    //QByteArray json = doc.toJson(QJsonDocument::Indented);//输出换行格式
    QByteArray json = doc.toJson(QJsonDocument::Compact);//输出一行格式
    qDebug() << json;

    //解析json
    //QJsonDocument doc2 = QJsonDocument::fromJson(json);
    //QJsonObject obj2 = doc2.object();
    //一行代码完成上面2行的功能
    QJsonObject obj2 = QJsonDocument::fromJson(json).object();
    if (obj2.value("name").toString() == "chengzhi")
    {
        qDebug() << "yes";
    }

}


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MyWidget w;
    w.show();

    return app.exec();
}
