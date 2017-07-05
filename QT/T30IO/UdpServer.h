#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QWidget>
#include <QUdpSocket>
#include <QDebug>
#include <QTimer>
#include <QDateTime>



class UdpServer : public QWidget
{
    Q_OBJECT
public:
    explicit UdpServer(QWidget *parent = 0);
    QUdpSocket* socket;

signals:

public slots:
    void slotReadyRead();

};

#endif // UDPSERVER_H
