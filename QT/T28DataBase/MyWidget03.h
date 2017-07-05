#ifndef MYWIDGET03_H
#define MYWIDGET03_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>
#include <QItemDelegate>
#include <QComboBox>



class MyDBDelegate : public QItemDelegate
{
public:
    // editing
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
    {
        if (0 == index.column())
        {
            return nullptr;
        }
        if (3 == index.column())
        {
            QComboBox* com = new QComboBox(parent);
            com->addItem("male");
            com->addItem("female");
            return com;
        }
        else
        {
            return QItemDelegate::createEditor(parent, option, index);
        }
    }
};



class ReadOnlyDelegate : public QItemDelegate
{
public:
    // editing
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
    {
        return nullptr;
    }
};



#if 1
class GenderDelegate : public QItemDelegate
{
public:
    // editing
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
    {
        QComboBox* com = new QComboBox(parent);
        com->addItem("male");
        com->addItem("female");
        return com;
    }

};

#endif

class MyQSqlTableModel : public QSqlTableModel
{
public:
    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const
    {
        if (idx.column() != 3)
        {
            return QSqlTableModel::data(idx, role);
        }
        QVariant var = QSqlTableModel::data(idx, role);
        if (1 == var)
        {
            return "male";
        }
        else
        {
            return "female";
        }
    }
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole)
    {
        if (index.column() != 3)
        {
            return setData(index, value, role);
        }
        if ("male" == value)
        {
            return QSqlTableModel::setData(index, 1, role);
        }
        else
        {
            return QSqlTableModel::setData(index, 0, role);
        }
    }

};



class MyWidget03 : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget03(QWidget *parent = 0);
    MyQSqlTableModel* model;
    QTableView* view;

signals:

public slots:
    void slotSubmitClicked();
    void slotAddClicked();
    void slotDelClicked();
};

#endif // MYWIDGET03_H
