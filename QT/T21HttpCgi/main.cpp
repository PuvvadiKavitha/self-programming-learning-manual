#include <stdio.h>
#include <unistd.h>

#include <QCoreApplication>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QProcessEnvironment>

//test - cgi

int main(int argc, char* argv[])
{
    QCoreApplication _app(argc, argv);
    QProcessEnvironment _ev = QProcessEnvironment::systemEnvironment();
    int _contentLen = _ev.value("CONTENT_LENGTH").toInt();
    QTcpSocket _socket;

    _socket.setSocketDescriptor(STDIN_FILENO,
                                QTcpSocket::ConnectedState,
                                QTcpSocket::ReadOnly);
    QByteArray _buf;
    QObject::connect(&_socket, &QTcpSocket::readyRead,[&]()
    {
        _buf += _socket.readAll();
        if (_buf.size() == _contentLen)
        {
            //read json
            QJsonDocument _doc = QJsonDocument::fromJson(_buf);
            QJsonObject _obj = _doc.object();
            QString _username = _obj.value("username").toString();
            QString _password = _obj.value("password").toString();
            printf("username is %s; password is %s",
                   _username.toUtf8().data(),
                   _password.toUtf8().data());
            _app.quit();

        }
    });









    return _app.exec();
}
