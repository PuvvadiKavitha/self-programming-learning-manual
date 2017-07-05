#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
class MyPushButton : public QWidget
{
    Q_OBJECT
public:
    QRect rect;
    QString text;
    explicit MyPushButton(QWidget *parent = 0);
    MyPushButton(const QString &p_text, QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
signals:

public slots:

};

#endif // MYPUSHBUTTON_H
