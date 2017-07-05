#include "MyWidget.h"



MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{

#if 0
    //内存映射,虚拟内存
    QFile file("../map.txt");
    file.open(QIODevice::ReadWrite);
    file.seek(1024);
    file.write("1");
    file.close();
    file.open(QIODevice::ReadWrite);

    uchar* ptr = file.map(0, 1024);

    *ptr = 'a';
    ptr[1] = 'b';

    //uchar ch = *ptr;

    file.unmap(ptr);
    file.close();
#endif

#if 0
    QFile file("../3.txt");
    file.open(QIODevice::ReadWrite);
    QDataStream textStream(&file);
    textStream << 1 << "aaa" << "chengzhi" << QPoint(1, 1);
    file.close();

#endif

#if 0
    QFile file("../3.txt");
    file.open(QIODevice::ReadWrite);
    //格式化写入和读取，避免大端小端问题,一次性写入，读取，永久化存储
    QDataStream textStream(&file);
    int i;
    char* s1;
    char* s2;
    QPoint pt;
    textStream >> i >> s1 >> s2 >> pt;
    qDebug() << i << s1 << s2 << pt;
    file.close();
#endif



#if 0
    QFile file("../2.txt");
    file.open(QIODevice::ReadWrite);
    QTextStream textStream(&file);
    textStream << 1 << "aaa" << "chengzhi";
    file.close();

#endif





#if 0
    //save file
    QBuffer buffer;//内存文件缓冲区
    buffer.open(QIODevice::ReadWrite);
    QPixmap pix("../aaa.png");
    pix.save(&buffer, "PNG");
    buffer.close();
    qDebug() << buffer.buffer().size();


    //receiver file
    QPixmap pix2;
    pix2.loadFromData(buffer.buffer(), "PNG");
    QLabel* label = new QLabel(this);
    label->setPixmap(pix2);

#endif

#if 0
    QFile file("../1.txt");//file name
    file.open(QIODevice::ReadWrite);//open mode
    file.write(QByteArray("chengzhi"));//do
    file.close();//close
#endif

#if 0
    QString str("陈登龙");//内部实现不是字节数组
    QByteArray arr("陈登龙");
    qDebug() << arr.size() << str.size();//3    9
#endif
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    UdpServer s;
    s.setWindowTitle("UdpServer");
    s.show();
    UdpClient c;
    c.setWindowTitle("UdpClient");
    c.show();



#if 0
    TcpServer s;
    s.setWindowTitle("TcpServer");
    s.show();
    TcpClient c;
    c.setWindowTitle("TcpClient");
    c.show();
#endif
    return app.exec();
}
