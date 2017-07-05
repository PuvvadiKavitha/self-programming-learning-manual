#ifndef MYWIDGET05_H
#define MYWIDGET05_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
class MyWidget05 : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget05(QWidget *parent = 0);

    QSqlTableModel* _model;
    QTableView* _view;

    QLineEdit* _filter;
    QPushButton* _add;
    QPushButton* _del;
    QPushButton* _reset;
    QPushButton* _submit;
signals:

public slots:

    void slotModelDataChanged(QModelIndex,QModelIndex);
    void slotFilterChanged(QString filter);

};

#endif // MYWIDGET05_H
