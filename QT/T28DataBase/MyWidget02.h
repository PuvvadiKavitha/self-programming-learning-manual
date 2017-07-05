#ifndef MYWIDGET02_H
#define MYWIDGET02_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>

class MyWidget02 : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget02(QWidget *parent = 0);
    QSqlTableModel* model;
    QTableView* view;

signals:

public slots:
    void slotSubmitClicked();
    void slotAddClicked();
    void slotDelClicked();

};

#endif // MYWIDGET02_H
