#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::setXY(int a, int b)
{
    this->x = a;
    this->y = b;
    this->resize(this->x, this->y);
}

Dialog* Dialog::operator ++()//++this
{
    qDebug() << "++this";
    this->x += 10;
    this->y += 10;
    this->setXY(this->x, this->y);
    return this;
}
#if 1
Dialog* Dialog::operator ++(int a)//this++,return a temp dialog then this's area += 100
{
    qDebug() << "this++";
    Dialog* ptemp = new Dialog;
    ptemp->x = this->x;
    ptemp->y = this->y;
    ptemp->setXY(this->x, this->y);
    ptemp->show();

    this->x += 40;
    this->y += 40;
    this->setXY(this->x, this->y);
    return ptemp;
}
#endif

Dialog* Dialog::operator +(const Dialog& dig)
{
    Dialog* ptemp = new Dialog;
    ptemp->x = this->x + dig.x;
    ptemp->y = this->y + dig.y;
    ptemp->setXY(ptemp->x, ptemp->y);
    return ptemp;
}

void Dialog::on_pushButton_clicked()
{
    ++(*this);
}

void Dialog::on_pushButton_2_clicked()
{
    (*this)++;
}
