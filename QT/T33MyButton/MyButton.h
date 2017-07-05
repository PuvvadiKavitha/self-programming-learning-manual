#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>

class MyButton : public QWidget
{
    Q_OBJECT
public:

    QRect rect;//按钮形状
    QString text;//按钮文字
    bool isPressed;//是否按下的标志
    explicit MyButton(QWidget *parent = 0);
    MyButton(const QString& p_text, QWidget* parent = 0);
    void paintEvent(QPaintEvent *);//重绘事件
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

signals:
    void clicked();

public slots:

};

#endif // MYBUTTON_H
