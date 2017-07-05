#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
//display scene
#include <QGraphicsView>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QMouseEvent>

#include <QPrintPreviewDialog>
#include <QPrintDialog>

#include <QTimer>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
    //MVC的思想
    QGraphicsScene* scene;//data model
    QGraphicsView* view;//show data model

    QTimer* time;
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
signals:

public slots:
    void slotPaintRequested(QPrinter*);
    void slotTimeout();

};

#endif // MYWIDGET_H
