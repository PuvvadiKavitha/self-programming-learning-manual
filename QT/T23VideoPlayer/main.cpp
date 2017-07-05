#include <QCoreApplication>
#include <QAudioInput>
#include <QFile>
#include <QTimer>
#include <QAudioDeviceInfo>
#include <QDebug>
#include <QAudioFormat>


int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    QString _fileName = "d:\\1.raw";
    QFile _file(_fileName);
    _file.open(QFile::ReadWrite);

    QAudioFormat _format;
    _format.setSampleRate(8000);
    _format.setChannelCount(1);
    _format.setSampleSize(8);
    _format.setCodec("codec/pcm");
    _format.setByteOrder(QAudioFormat::LittleEndian);

    QAudioDeviceInfo _dev = QAudioDeviceInfo::defaultInputDevice();

    if (!_dev.isFormatSupported(_format))
    {
        _format = _dev.nearestFormat(_format);
        //必须记录文件的格式
        qDebug() <<   _format.sampleRate();
        qDebug() <<  _format.sampleSize();
        qDebug() <<   _format.sampleType();
        qDebug() <<  _format.codec();
        qDebug() <<  _format.byteOrder();
        qDebug() <<   _format.channelCount();
    }

    QAudioInput* _audio = new QAudioInput(_format);
    _audio->setNotifyInterval(200);//1s5帧
    //1.直接录制
    //_audio->start(&_file);

    //2.按照帧的方式录制
    QIODevice* _audioData = _audio->start();

    app.connect(_audio, &QAudioInput::notify, [&]()
    {
        //可读的数据的大小
        int _bytesReady = _audio->bytesReady();
        QByteArray _b(_bytesReady, 0);
        //写入字节数组中
        _audioData->read(_b.data(), _bytesReady);
        //将字节数组写入文件
        _file.write(_b);
    });
 

    QTimer* _t = new QTimer;
    _t->setInterval(5000);
    _t->start();
    QObject::connect(_t, &QTimer::timeout, [&]()
    {
        _audio->stop();
        _audio->deleteLater();
        _file.close();
        app.quit();
    });
    return app.exec();
}
