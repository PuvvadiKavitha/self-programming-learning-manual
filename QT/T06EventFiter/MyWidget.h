#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    QPushButton *_button;
    explicit MyWidget(QWidget *parent = 0);
    bool eventFilter(QObject *, QEvent *);
    bool event(QEvent *);
signals:

public slots:

};

#endif // MYWIDGET_H
