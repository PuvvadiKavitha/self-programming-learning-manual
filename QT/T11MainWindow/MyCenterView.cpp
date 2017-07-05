#include "MyCenterView.h"

MyCenterView::MyCenterView(QWidget *parent) :
    QWidget(parent)
{
}


void MyCenterView::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //painter.fillRect(QRectF(0, 0, 100, 100), Qt::red);
    painter.fillRect(rect(), Qt::red);
}

