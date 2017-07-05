#include "UdpClient.h"

UdpClient::UdpClient(QWidget *parent) :
    QWidget(parent)
{
	


    this->socket = new QUdpSocket;
    this->socket->bind(10001);

    //接收数据
    connect(this->socket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));

    //定时发送
    QTimer* timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect(timer, &QTimer::timeout,
            [&](){
        //获取自1970年1月1日起的时间(毫秒为单位)
        quint64 timetStamp = QDateTime::currentMSecsSinceEpoch();
        QString str = QString::number(timetStamp);
#if 0
        //普通发送
        this->socket->writeDatagram(str.toUtf8(), QHostAddress("127.0.0.1"), 10002);
#elif 1
        //广播发送
        this->socket->writeDatagram(str.toUtf8(), QHostAddress::Broadcast, 10002);
#else
        //多播发送
        this->socket->writeDatagram(str.toUtf8(), QHostAddress("224.0.0.131"), 10002);
#endif


    });
}

void UdpClient::slotReadyRead()
{
    //有数据报才发送
    while (this->socket->hasPendingDatagrams())
    {
        //获取数据报
        quint32 data = this->socket->pendingDatagramSize();
        //转换为字节数组
        QByteArray buffer(data, 0);
        //读取数据报，指定数据和大小
        this->socket->readDatagram(buffer.data(), buffer.size());
        qDebug() << "UdpClient" << buffer;

    }
}
