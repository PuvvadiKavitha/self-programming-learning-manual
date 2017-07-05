#include "UdpServer.h"

UdpServer::UdpServer(QWidget *parent) :
    QWidget(parent)
{
    this->socket = new QUdpSocket;
#if 1
    //普通和广播
    this->socket->bind(10002);
#elif 0
    //多播，需要加入多播地址
    this->socket->bind(QHostAddress::AnyIPv4, 10002);
    this->socket->joinMulticastGroup(QHostAddress("224.0.0.131"));
#endif
    //接收数据
    connect(this->socket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));
    //定时发送
    QTimer* timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect(timer, &QTimer::timeout,
            [&](){
        quint64 timerStamp = QDateTime::currentMSecsSinceEpoch();
        QString str = QString::number(timerStamp);
        this->socket->writeDatagram(str.toUtf8(), QHostAddress("127.0.0.1"), 10001);

    });
}

void UdpServer::slotReadyRead()
{
    while (this->socket->hasPendingDatagrams())
    {
        quint32 data = this->socket->pendingDatagramSize();
        QByteArray buffer(data, 0);
        this->socket->readDatagram(buffer.data(), buffer.size());
        qDebug() << "UdpServer" << buffer;

    }
}
