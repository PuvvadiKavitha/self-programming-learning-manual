#include <QCoreApplication>
#include <QAudioOutput>
#include <QFile>
#include <QTimer>
#include <QAudioDeviceInfo>
#include <QDebug>
#include <QAudioFormat>


int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    QFile _file("d:\\1.raw");
    //open file
    if (!_file.open(QFile::ReadOnly))
    {
        qDebug() << "open file error";
        exit(0);
    }
/*
8000
8
SignedInt
"audio/pcm"
LittleEndian
1
*/
    //format file
    QAudioFormat _format;
    _format.setSampleRate(8000);
    _format.setSampleSize(8);
    _format.setSampleType(QAudioFormat::SignedInt);
    _format.setCodec("audio/pcm");
    _format.setByteOrder(QAudioFormat::LittleEndian);
    _format.setChannelCount(1);


    //out audio
    QAudioOutput* _out = new QAudioOutput(_format);

    //start
    _out->start(&_file);

    return app.exec();
}
