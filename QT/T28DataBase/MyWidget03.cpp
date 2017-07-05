#include "MyWidget03.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include <QItemSelectionModel>

MyWidget03::MyWidget03(QWidget *parent) :
    QWidget(parent)
{
    this->model = new MyQSqlTableModel;
    model->setTable("tuser");
    model->select();
    //set submit model = shoudong
    this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //set column name
    this->model->setHeaderData(0, Qt::Horizontal, "Index");
    this->model->setHeaderData(1, Qt::Horizontal, "username");
    this->model->setHeaderData(2, Qt::Horizontal, "password");
    this->model->setHeaderData(3, Qt::Horizontal, "gender");

    //chaxun
    this->view = new QTableView;
    this->view->setModel(this->model);
    //set view Delegate
    //1.Table Delegate-easy
    //this->view->setItemDelegateForColumn(3, new GenderDelegate);
    //this->view->setItemDelegateForColumn(0, new ReadOnlyDelegate);
    //2.Database Delegate-the fun will too big
    this->view->setItemDelegate(new MyDBDelegate);

    /*hide some column etc:password*/
    //this->view->hideColumn(2);

    //set layout
    QVBoxLayout* lay = new QVBoxLayout(this);
    lay->addWidget(this->view);
    QHBoxLayout* hbox = new QHBoxLayout;
    lay->addLayout(hbox);
    hbox->addStretch();

    //edit record
    QPushButton* submit = new QPushButton("submit");
    connect(submit, SIGNAL(clicked()),
            this, SLOT(slotSubmitClicked()));
    hbox->addWidget(submit);

    //add record
    QPushButton* add = new QPushButton("add");
    connect(add, SIGNAL(clicked()),
            this, SLOT(slotAddClicked()));
    hbox->addWidget(add);

    //delete record
    QPushButton* del = new QPushButton("delete");
    connect(del, SIGNAL(clicked()),
            this, SLOT(slotDelClicked()));
    hbox->addWidget(del);
}


//Del record slot function
void MyWidget03::slotDelClicked()
{
    //Get select part data model
    QItemSelectionModel* _selectModel = this->view->selectionModel();
    //Get ModelIndex by the data model
    QModelIndexList _selectList = _selectModel->selectedIndexes();
    QList<int> _delRow;
    //Get all select Rows by the Model
    for (int i = 0; i < _selectList.size(); i++)
    {
        QModelIndex _index = _selectList.at(i);
        _delRow << _index.row();
    }
    //Del the same the row
    while (_delRow.size() > 0)
    {
        int _row = _delRow.at(0);
        _delRow.removeAll(_row);
        this->model->removeRow(_row);
    }
    //Submit
    this->model->submitAll();
}

//add slot function
void MyWidget03::slotAddClicked()
{
    //start transaction
    this->model->database().transaction();

    QSqlRecord record = this->model->record();
    this->model->insertRecord(-1, record);
}


//submit function
void MyWidget03::slotSubmitClicked()
{
    //submit false
    if (this->model->submitAll() == false)
    {
        //my window : Driver no loader
        QMessageBox::critical(this, "Error", QSqlDatabase().lastError().text());
        this->model->database().rollback();//rollback all model
    }
    else
    {
        this->model->database().commit();
    }
}





