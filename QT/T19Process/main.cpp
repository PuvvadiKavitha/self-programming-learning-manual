#include <QCoreApplication>
#include <QProcess>
#include <QDebug>



int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    QProcess _process;
    //开启一个进程
    _process.start("C:\\Users\\Administrator\\Desktop\\1.exe");

    //向进程写入信息
    //_process.write("1\n", 2);


    //_process.start("calc");

    //开启后台进程,与主进程无关，是独立的进程
    //_process.startDetached("notepad");

    //进程结束会调用QProcess的finish函数
    //重载的函数不能用lambda表达式

    //阻塞主进程，等待主进程结束
    _process.waitForFinished();

    //读取进程信息
    qDebug() << _process.readAll();
    return app.exec();
}
