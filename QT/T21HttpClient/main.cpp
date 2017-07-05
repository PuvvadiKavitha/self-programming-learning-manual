#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    //****1.NetWork Manager
    QNetworkAccessManager* _m = new QNetworkAccessManager;
#if 0
    //2.NetWorkRequest
    QNetworkRequest _request;
    _request.setUrl(QUrl("http://127.0.0.1/"));
    //_request.setUrl(QUrl("http://127.0.0.1/cgi_test1.cgi"));
    //start get or post
    _m->get(_request);
    //ok-lambda
    QObject::connect(_m, &QNetworkAccessManager::finished, [](QNetworkReply* reply){
            if (reply->error() != QNetworkReply::NoError)
            {
                qDebug() << "Error:" << reply->errorString();
                return ;
            }
            QByteArray buf = reply->readAll();
            qDebug() << "OK:" << buf;
    });

#endif

    //use json
    QJsonObject _obj;
    _obj.insert("username", QString("chengzhi"));
    _obj.insert("password", QString("123456789"));

    //request object
    QNetworkRequest _request;
    //set url
    _request.setUrl(QUrl("http://127.0.0.1/cgi-bin/qt-test.cgi"));
    _m->post(_request, QJsonDocument(_obj).toJson());

    //test
    QObject::connect(_m, &QNetworkAccessManager::finished, [](QNetworkReply* reply){
            if (reply->error() != QNetworkReply::NoError)//error
            {
                qDebug() << "Error:" << reply->errorString();
                return ;
            }
            //read
            QByteArray buf = reply->readAll();
            qDebug() << "OK:" << buf;
    });


    return app.exec();

}
