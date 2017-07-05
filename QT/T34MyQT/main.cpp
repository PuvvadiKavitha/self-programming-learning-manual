#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget w;
    w.setWindowTitle("Hello World");

    QPushButton button;
    button.setText("Exit");
    button.setParent(&w);
    //button.show();
    w.show();
    QObject::connect(&button, SIGNAL(clicked()), &w, SLOT(close()));
    return app.exec();
}
