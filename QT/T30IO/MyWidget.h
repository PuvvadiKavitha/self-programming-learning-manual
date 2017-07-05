#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QFile>
#include <QApplication>
#include <QDebug>
#include <QBuffer>
#include <QPixmap>
#include <QLabel>
#include <QTextStream>
#include <QDataStream>
#include <QDebug>
#include <TcpServer.h>
#include <TcpClient.h>
#include <UdpClient.h>
#include <UdpServer.h>


class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

signals:

public slots:

};

#endif // MYWIDGET_H
