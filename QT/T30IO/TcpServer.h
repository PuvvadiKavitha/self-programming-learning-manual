#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QMessageBox>
#include "ChooseInterface.h"

#include <QLocalServer>//本地通信，用于进程间通信
#include <QLocalSocket>

#include <QDebug>
class TcpServer : public QWidget
{
    Q_OBJECT
public:
    explicit TcpServer(QWidget *parent = 0);
    QTcpServer* server;
    QTcpSocket* socket;
    QTextBrowser* textBrowser;
    ChooseInterface* selectIpDlg;


signals:

public slots:
    void slotNetConnection();
    void slotReadyRead();

};

#endif // TCPSERVER_H
