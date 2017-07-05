#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "MyButton.h"

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyButton *my_text_button;
    MyButton *my_exit_button;
    explicit MyWidget(QWidget *parent = 0);

signals:

public slots:
    void buttonClickedSlot();

};

#endif // MYWIDGET_H
