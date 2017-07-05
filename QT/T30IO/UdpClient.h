#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QWidget>
#include <QUdpSocket>
#include <QDebug>
#include <QTimer>
#include <QDateTime>

class UdpClient : public QWidget
{
    Q_OBJECT
public:
    explicit UdpClient(QWidget *parent = 0);
    QUdpSocket* socket;

signals:

public slots:
    void slotReadyRead();

};

#endif // UDPCLIENT_H
