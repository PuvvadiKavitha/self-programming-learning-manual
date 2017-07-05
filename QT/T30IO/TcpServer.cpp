#include "TcpServer.h"

TcpServer::TcpServer(QWidget *parent) :
    QWidget(parent)
{
    //创建服务并且监听
    server = new QTcpServer;
    //弹出对话框选择要监听的ip地址
    selectIpDlg = new ChooseInterface;
    selectIpDlg->exec();

    //接收ip和端口
    server->listen(QHostAddress(this->selectIpDlg->selectIP), this->selectIpDlg->port);
    qDebug() << this->selectIpDlg->selectIP + ":" + QString::number(this->selectIpDlg->port);
    //QString msg = this->selectIpDlg->selectIP + ":" + QString::number(this->selectIpDlg->port);
    QMessageBox::information(NULL, "Ip:", this->selectIpDlg->selectIP );
    //客户端连接的监听
    connect(server, SIGNAL(newConnection()), this, SLOT(slotNetConnection()));

    textBrowser = new QTextBrowser;
    QVBoxLayout* lay = new QVBoxLayout(this);
    lay->addWidget(textBrowser);
}

void TcpServer::slotNetConnection()
{
    //判断是否有未处理的连接
    while (server->hasPendingConnections())
    {
        this->textBrowser->append("New Connection...");
        //获取连接
        socket = server->nextPendingConnection();
        //为连接的Socket提供槽函数来接收数据
        connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    }
}

void TcpServer::slotReadyRead()
{
    //判断是否有数据
    while (socket->bytesAvailable() > 0)
    {
        this->textBrowser->append("msg comming...");
        QByteArray buffer = socket->readAll();
        textBrowser->append(buffer);
    }
}








