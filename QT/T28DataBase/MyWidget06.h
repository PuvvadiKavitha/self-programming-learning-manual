#ifndef MYWIDGET06_H
#define MYWIDGET06_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QTableView>

class MyWidget06 : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget06(QWidget *parent = 0);
    QSqlQueryModel* model;
    QTableView* view;
signals:

public slots:

};

#endif // MYWIDGET06_H
