#include "MyWidget.h"
#include <QApplication>
#include <QEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QPainter>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
     QVBoxLayout *Layout = new QVBoxLayout(this);
#if 0
    QPushButton *button2;
    Layout->addWidget(button = new QPushButton("OK", this));
    Layout->addWidget(button2 = new QPushButton("Exit", this));
    //mouse move 不需要点击移动也会响应的设置
    this->setMouseTracking(true);
    //button->setMouseTracking(true);鼠标移动到button上, 不点击, button仍然有效果, 必须设置这个属性
    button->setDefault(true);//按钮获取焦点
    //connect(button, &QPushButton::clicked, [](){
    //    qDebug() << "Button Clicked";
    //});
    connect(button, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
    connect(button2, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
#endif

#if 0
    Layout->addWidget(edit = new QLineEdit);
    connect(edit, SIGNAL(returnPressed()), this, SLOT(ButtonClicked()));
#endif

}
/*窗口事件*/
void MyWidget::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.drawLine(QPoint(0, 0), QPoint(100, 100));
}

void MyWidget::closeEvent(QCloseEvent *ev)
{
    //ev->ignore();
    qDebug() << "Close Event";
}

void MyWidget::showEvent(QShowEvent *ev)
{
    qDebug() << "show Event";
}

void MyWidget::hideEvent(QHideEvent *ev)
{
    qDebug() << "hide Event";
}

/*槽函数*/
void MyWidget::ButtonClicked()
{
    qDebug() << "Button Clicked" << ((QLineEdit *)sender())->text();
}

/*所有事件的基类*/
bool MyWidget::event(QEvent *ev)
{
    if (ev->type() == QEvent::MouseButtonPress)
    {
        //qDebug() << "鼠标事件被劫持了";
        //return true;
    }
    //ev->ignore();忽略所有消息 劫持全部
    return QWidget::event(ev);
}

/*鼠标事件*/
void MyWidget::mousePressEvent(QMouseEvent *ev)
{
    //QPoint pt = ev->pos();
    //qDebug() << pt;
#if 1
    if (ev->button() == Qt::LeftButton)
    {
        qDebug() << "鼠标左键被点击";
    }
    if (ev->button() == Qt::RightButton)
    {
        qDebug() << "鼠标右键被点击";
    }
    if (ev->modifiers() == Qt::ShiftModifier)
    {
        qDebug() << "shift press";
    }
#endif
    //工作中的代码结构 重要
    if (ev->type() == Qt::LeftButton)
    {
        if (ev->modifiers() == Qt::ControlModifier)
        {
            //handle control + left
            qDebug() << "control left press";
        }
        //handler left
    }
    else
    {

    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        qDebug() << "鼠标左键被释放";
    }
    if (ev->button() == Qt::RightButton)
    {
        qDebug() << "鼠标右键被释放";
    }
    if (ev->modifiers() == Qt::ShiftModifier)
    {
        qDebug() << "shift Release";
    }
    if (ev->modifiers() == Qt::ControlModifier)
    {
        qDebug() << "control Release";
    }
}

void MyWidget::mouseMoveEvent(QMouseEvent *ev)
{
    static int i = 0;//测试鼠标移动的焦点
    qDebug() << "鼠标被移动" << ++i;
}

/*键盘事件*/
void MyWidget::keyPressEvent(QKeyEvent *ev)
{
    int key = ev->key();
    qDebug() << key;
    char ch = key;
    qDebug() << (char)ch << "被按下";//qt只处理大写字母
}

void MyWidget::keyReleaseEvent(QKeyEvent *ev)
{
    qDebug() << (char)(ev->key()) << "键被释放";
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget w;
    w.show();
    return app.exec();
}
