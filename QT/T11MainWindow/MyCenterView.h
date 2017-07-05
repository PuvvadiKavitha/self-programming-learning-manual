#ifndef MYCENTERVIEW_H
#define MYCENTERVIEW_H

#include <QWidget>
#include <QPainter>
class MyCenterView : public QWidget
{
    Q_OBJECT
public:
    explicit MyCenterView(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);


signals:

public slots:

};

#endif // MYCENTERVIEW_H
