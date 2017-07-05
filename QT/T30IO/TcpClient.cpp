#include "TcpClient.h"

TcpClient::TcpClient(QWidget *parent) :
    QWidget(parent)
{
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 9988);//连接
    edit = new QLineEdit;
    QHBoxLayout* lay = new QHBoxLayout(this);
    lay->addWidget(edit);
    QPushButton* button = new QPushButton("send");
    lay->addWidget(button);

    //发送
    connect(button, SIGNAL(clicked()), this,
            SLOT(slotSend()));
    //回车发送
    connect(edit, SIGNAL(returnPressed()), this,
            SLOT(slotSend()));
}

void TcpClient::slotSend()
{
    //取出信息发送
    QString text = edit->text();
    if (text.isEmpty())
    {
        return;
    }
    socket->write(text.toUtf8());//以text.toUtf8()字节数组形式
    edit->clear();//编辑框清除
}
