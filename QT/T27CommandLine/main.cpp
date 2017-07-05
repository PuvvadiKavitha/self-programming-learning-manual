#include <QCoreApplication>
#include <QCommandLineParser>
#include <cstdlib>
#include <QDebug>


int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    //Set app name
    app.setApplicationName("CommandLine");
    //Set app version
    app.setApplicationVersion("1.0");

    QCommandLineParser _parser;
    //CommandLineParser add Help Option
    _parser.addHelpOption();
    //CommandLineParser add Version Option
    _parser.addVersionOption();

    //Set the commandline argment 'p'
    //The default is com.itcast.hello
    QCommandLineOption p(QStringList() << "p" << "package", "set package name of Android", "com.itcast.hello");
    //Add the option 'p'
    _parser.addOption(p);
    //Set the commandline option 'l'
    QCommandLineOption l(QStringList() << "l" << "language", "set code language c++ or lua", "c++");
    _parser.addOption(l);

    //Exec commandline parser
    //_parser.process(app.arguments());
    _parser.process(app);//Use this

    //When the user input the 'p', get the 'p' argcment and to do something
    QString _value = _parser.value("p");
    printf("p is %s\n", _value.toUtf8().data());

    //When the user input the 'l', get the 'l' argcment and to do something
    _value = _parser.value("l");
    printf("l is %s\n", _value.toUtf8().data());


    //Get other argc is no '-argc'
    qDebug() << _parser.positionalArguments();



    return app.exec();
}
