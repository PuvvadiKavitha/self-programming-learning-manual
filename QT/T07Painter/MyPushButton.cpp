#include "MyPushButton.h"

MyPushButton::MyPushButton(QWidget *parent) :
    QWidget(parent), rect(0, 0, 100, 30) ,text(QString())
{
    this->setGeometry(this->rect);

}

MyPushButton::MyPushButton(const QString &p_text, QWidget *parent) :
     rect(0, 0, 100, 30), text(p_text)
{
    this->setGeometry(this->rect);
}


void MyPushButton::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    //p.setBrush(Qt::darkGray);
    p.drawRect(this->rect);
    p.drawText(this->rect, this->text, QTextOption(Qt::AlignCenter));

}







