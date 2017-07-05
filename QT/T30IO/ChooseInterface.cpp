#include "ChooseInterface.h"

ChooseInterface::ChooseInterface(QWidget *parent) :
    QDialog(parent)
{
    //列出所有的ip
    QList<QHostAddress> addList = QNetworkInterface::allAddresses();
#if 0
    QList<QNetworkInterface> infList = QNetworkInterface::allInterfaces();

    QList<QNetworkAddressEntry> entryList = infList.at(0).addressEntries();
    entryList.at(0).broadcast();
#endif
    //添加三个控件
    this->ipCom = new QComboBox;
    QVBoxLayout* lay = new QVBoxLayout(this);
    lay->addWidget(this->ipCom);

    this->editPort = new QLineEdit;
    lay->addWidget(this->editPort);

    QPushButton *button = new QPushButton("ok", this);
    lay->addWidget(button);

    //添加ip
    foreach (QHostAddress add, addList)
    {
        quint32 ip = add.toIPv4Address();
        if (ip == 0)//ip = 0不添加显示
        {
            continue;
        }
        this->ipCom->addItem(QHostAddress(ip).toString());
    }

    //ip选择信号
    connect(this->ipCom, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(slotCurrentIndexChanged(QString)));

    //按钮ok信号
    connect(button, SIGNAL(clicked()),
            this, SLOT(slotOK()));

    //QLineEdit回车信号
    connect(this->editPort, SIGNAL(returnPressed()),
            this, SLOT(slotOK()));

}

void ChooseInterface::slotOK()
{
    this->port = this->editPort->text().toInt();
    this->close();
}

void ChooseInterface::slotCurrentIndexChanged(QString str)
{
    this->selectIP = str;
}






