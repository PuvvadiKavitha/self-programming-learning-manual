#ifndef MYWIDGET04_H
#define MYWIDGET04_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>
#include <QCompleter>
class MyWidget04 : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget04(QWidget *parent = 0);
    QSqlTableModel* model;
    QTableView* view;

    QLineEdit* filterLine;
    QPushButton* add;
    QPushButton* del;
    QPushButton* reset;
    QPushButton* submit;

signals:

public slots:
    void slotAddClicked();
    void slotFilterChanged(QString);
    void slotModelDataChanged(QModelIndex, QModelIndex);
    void slotDelClicked();

};

#endif // MYWIDGET04_H
