#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "MyPushButton.h"
#include <QMouseEvent>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyPushButton *my_button;
    //QVector<QPoint> line;
    QVector< QVector<QPoint> > lines;
    explicit MyWidget(QWidget *parent = 0);
    //void paintEvent(QPaintEvent *);
    //void mousePressEvent(QMouseEvent *);
    //void mouseReleaseEvent(QMouseEvent *);
   // void mouseMoveEvent(QMouseEvent *);

signals:

public slots:

};

#endif // MYWIDGET_H
