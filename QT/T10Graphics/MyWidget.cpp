#include "MyWidget.h"
#include <QApplication>
#include <QDebug>
#include <QPrinter>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    this->scene = new QGraphicsScene();//数据
    this->view = new QGraphicsView(this->scene, this);//显示数据的view
    //this->view->setBackgroundBrush(Qt::red);//设置view的背景
    //this->view->setScene(this->scene);

    //每一个Item很灵活，有自己的操作
    QGraphicsLineItem* lineItem;
    QGraphicsTextItem* textItem;
    //添加两个item
    this->scene->addItem(lineItem = new QGraphicsLineItem(QLineF(QPointF(0, 0), QPointF(100, 100))));
    this->scene->addItem(textItem = new QGraphicsTextItem("Hello chengzhi"));
    QTransform textTran;
    textTran.rotate(30);
    textItem->setTransform(textTran);
    textItem->setPos(QPointF(200, 300));//设置位置
    textItem->setFont(QFont("AAA", 50, 700, true));//设置字体

    QGraphicsPixmapItem* pixmapItem;//添加图片
    this->scene->addItem(pixmapItem = new QGraphicsPixmapItem(QPixmap("../aaa.png")));
    pixmapItem->setPos(100, 100);//设置位置

    QGraphicsItemAnimation* anim = new QGraphicsItemAnimation;//设置动画
    anim->setItem(pixmapItem);//添加item到动画中
    QTimeLine* timeline = new QTimeLine(3000);//设置持续时间
    timeline->setLoopCount(2);
    anim->setTimeLine(timeline);
    anim->setTranslationAt(1, 200, 300);//设置为位移动画
    //timeline->start();//开始动画


#if 0
    time = new QTimer;
    time->setInterval(1000);//设置间隔时间
    connect(time, SIGNAL(timeout()), this, SLOT(slotTimeout()));//设置超时信号
    time->start();//计时开始
#endif
    //定时一次
    QTimer::singleShot(1000, this, SLOT(slotTimeout()));
}

void MyWidget::slotTimeout()
{
    qDebug() << "time out!";
    //sender()->deleteLater();执行一次后取消定时
}


void MyWidget::paintEvent(QPaintEvent *ev)
{

}


void MyWidget::resizeEvent(QResizeEvent *ev)
{
    this->view->setGeometry(QRect(QPoint(0, 0), size()));
}

void MyWidget::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::RightButton)//右键
    {
#if 0
        //qDebug() << "aaa";
        QPixmap pix(this->size());
        QPainter painter(&pix);
        painter.fillRect(QRect(0, 0, this->size().width(), this->size().height()), Qt::white);
        this->view->render(&painter);//每一个窗口都有render，scene也有
        //this->scene->render(&painter);
        pix.save("../painter.png");//保存图片
#endif
#if 0
        //打印预览
        QPrintPreviewDialog printDialog;
        connect(&printDialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(slotPaintRequested(QPrinter*)));
        printDialog.exec();
#endif
        //真实打印
        QPrintDialog dig;
        connect(&dig, SIGNAL(accepted(QPrinter*)), this, SLOT(slotPaintRequested(QPrinter*)));
        dig.exec();
    }
}

void MyWidget::slotPaintRequested(QPrinter *printer)
{
    QPainter painter(printer);
    this->scene->render(&painter);
    painter.drawText(QPoint(100, 100), "chengzhi");
}

/* Qt的图像类:QPixmap-常用-所在相关系统优化过的最好的格式,
 * QImage,像素点是24或者32位，内存较大
 * QBitmap,
 * QPicture
 */

/*打印相关的类：QPrinter QPainter QPixmap QPrintPreviewDialog QPrintDialog*/


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget w;
    w.show();//正常显示
    //w.showMaximized();最大
    //w.showMinimized();缩小到底部
    //w.showFullScreen();全屏显示不是最大化
    //w.showNormal();正常显示
    return app.exec();
}











