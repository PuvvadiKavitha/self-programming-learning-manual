#include "MyButton.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
MyButton::MyButton(QWidget *parent) :
    QWidget(parent), rect(0, 0, 100, 30), text(QString())
{
    this->isPressed = false;//开始处于非点击状态
    this->setGeometry(rect);//设置默认显示的位置
}

MyButton::MyButton(const QString &p_text, QWidget *parent):
    QWidget(parent), rect(0, 0, 100, 30), text(p_text)
{
    this->isPressed = false;
    this->setGeometry(rect);//设置默认显示的位置
}

void MyButton::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);//提高画笔质量
    if (this->isPressed)//根据状态显示按钮状态
    {
        p.setBrush(Qt::darkGray);
    }
    else
    {
        p.setBrush(Qt::yellow);
    }
    //p.drawRect(rect);
    p.drawRoundRect(this->rect);//圆角矩形
    p.drawText(rect, text, QTextOption(Qt::AlignCenter));//文字居中对齐
}

void MyButton::mousePressEvent(QMouseEvent *ev)
{
    this->isPressed = true;
    update();//必须重绘界面

}

void MyButton::mouseReleaseEvent(QMouseEvent *ev)
{
    this->isPressed = false;
    update();//必须重绘界面
    if(this->rect.contains(ev->pos()))//在button内部点击才有效
    {
        emit clicked();
        //qDebug() << "signal has emit!";
    }
}


