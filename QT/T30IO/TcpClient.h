#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>


class TcpClient : public QWidget
{
    Q_OBJECT
public:
    explicit TcpClient(QWidget *parent = 0);
    QTcpSocket* socket;
    QLineEdit* edit;
signals:

public slots:
    void slotSend();

};

#endif // TCPCLIENT_H
