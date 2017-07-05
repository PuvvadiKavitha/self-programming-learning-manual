
#include <QCoreApplication>
#include "../T16StaticLib/T16StaticLib.h"



int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    T16StaticLib b;
    b.Encrypt();
    return app.exec();
}
