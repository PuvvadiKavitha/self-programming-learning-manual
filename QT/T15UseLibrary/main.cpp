#include <QCoreApplication>
#include "../T14Library/T14Library.h"



int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    T14Library b;
    b.Encrypt();
    return app.exec();
}
