#include "MyWidget.h"
#include <QDebug>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    my_text_button = new MyButton("my_text_button", this);
    connect(my_text_button, SIGNAL(clicked()), this, SLOT(buttonClickedSlot()));//信号
    my_text_button->setGeometry(30, 30, 100, 30);

    my_exit_button = new MyButton("my_exit_button", this);
    connect(my_exit_button, SIGNAL(clicked()), this, SLOT(close()));//关闭信号
    my_exit_button->setGeometry(200, 30, 100, 30);
}

void MyWidget::buttonClickedSlot()
{
    qDebug() << "emit has been receiver!";
}

#include <QApplication>
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MyWidget w;
    w.show();

    return app.exec();
}
