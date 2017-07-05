#include "MyWidget.h"
#include <QApplication>
#include <QPainter>

#include <QVector>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{

    this->my_button = new MyPushButton("MyButton", this);

}

#if 0

void MyWidget::paintEvent(QPaintEvent *ev)
{
    //*******提高绘图的效率，先画在一张图上，然后将图一次性画在主窗口上******
    QPixmap pix(size());
    QPainter p(&pix);

    //QPainter p(this);

    QTransform transform;
    transform.rotate(30);//旋转
    transform.scale(0.5, 0.5);
    p.setTransform(transform);

    QTransform transform2;//使用QTransform类来转换
    transform2.rotate(10);//旋转
    transform2.scale(0.3, 0.3);
    p.setTransform(transform2, false);//是否与之前的transform组合，false不组合，true组合


    //自己有一套转换机制
    p.translate(100, 100);//平移
    p.scale(0.6, 0.6);
    p.rotate(-10);

    p.setRenderHint(QPainter::Antialiasing);//提高线的质量
    p.setPen(QPen(Qt::red, 2, Qt::DashLine));//画笔
    p.setBrush(Qt::yellow);//画刷
    p.setFont(QFont("Helvetica", 40, 700, true));//字体-大小-加粗-斜体
    p.drawLine(QPoint(0, 0), QPoint(100, 100));//线
    p.translate(-100, -100);//回到平移前的效果
    p.drawEllipse(QPoint(100, 300), 50, 50);//椭圆
    p.drawText(QPoint(300, 50), "Hello World");//画文字
    p.drawRoundRect(QRect(40, 60, 100, 50));//圆角矩形
    //p.drawPixmap(QPoint(40, 40), QPixmap("../aaa.png"));//画图片


    //*********重要************
    p.end();//结束画图
    p.begin(this);//重新将pixmap图画在主窗口上
    p.drawPixmap(0, 0, pix);//开始画

}
#endif

#if 0

void MyWidget::paintEvent(QPaintEvent *ev)
{
    //实现划线的功能
    QPainter p(this);
    for (int i = 0; i < line.size() - 1; i++)
    {
        p.drawLine(line.at(i), line.at(i + 1));//line.size() - 1只能到i - 1
    }

}

void MyWidget::mouseMoveEvent(QMouseEvent *ev)
{
    //ing
    line.append(ev->pos());
    update();//强制刷新，调用paintEvent重绘界面
}

void MyWidget::mousePressEvent(QMouseEvent *ev)
{
    //begin
    line.append(ev->pos());
    update();

}

void MyWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    //end
    line.append(ev->pos());
    update();

}

#endif

#if 0
/*一个实用的写字板*/
void MyWidget::paintEvent(QPaintEvent *ev)
{
    //实现划线的功能
    QPainter p(this);
    for (int i = 0; i < lines.size(); i++)
    {
        const QVector<QPoint> &_line = lines.at(i);
        for (int j = 0; j < _line.size() - 1; j++)
        {
            p.drawLine(_line.at(j), _line.at(j + 1));
        }
    }

}

void MyWidget::mouseMoveEvent(QMouseEvent *ev)
{
    //ing
    QVector<QPoint> &lastline = lines.last();
    lastline.append(ev->pos());
    update();//强制刷新，调用paintEvent重绘界面
}

void MyWidget::mousePressEvent(QMouseEvent *ev)
{
    if ((ev->button() == Qt::RightButton) && (ev->type() == QEvent::MouseButtonPress ||
                                              ev->type() == QEvent::MouseButtonDblClick ||
                                              ev->type() == QEvent::MouseButtonRelease))
    {

        if (!lines.isEmpty())
        {
            lines.erase(lines.end() - 1);
            qDebug() << "RightButton" << lines.size();
            update();
            return;
        }

    }
    else if (ev->button() == Qt::LeftButton)
    {
        //begin
        QVector<QPoint> _line;
        lines.append(_line);

        QVector<QPoint> &lastline = lines.last();
        lastline.append(ev->pos());
        update();
    }
    else
    {
        return ;
    }


}

void MyWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    //end
    if (!lines.isEmpty())
    {
        QVector<QPoint> &lastline = lines.last();
        lastline.append(ev->pos());
    }


}
#endif


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget w;
    w.show();
    return app.exec();
}



