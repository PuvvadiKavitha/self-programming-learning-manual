#include "MyWidget04.h"

MyWidget04::MyWidget04(QWidget *parent) :
    QWidget(parent)
{
    //set table
    this->model = new QSqlTableModel;
    this->view = new QTableView;
    this->model->setTable("tuser");
    this->view->setModel(this->model);
    this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);


    connect(this->model, SIGNAL(dataChanged(QModelIndex,QModelIndex)),
            this, SLOT(slotModelDataChanged(QModelIndex, QModelIndex)));

    //select
    this->model->select();

    //set layout
    QVBoxLayout* VBox = new QVBoxLayout(this);
    VBox->addWidget(this->view);
    QHBoxLayout* HBox = new QHBoxLayout;
    VBox->addLayout(HBox);
    HBox->addWidget(this->filterLine = new QLineEdit, 1);
    HBox->addWidget(this->add = new QPushButton("Add"));
    HBox->addWidget(this->del = new QPushButton("Del"));
    HBox->addWidget(this->reset = new QPushButton("Reset"));
    HBox->addWidget(this->submit = new QPushButton("Submit"));

#if 1
    //add record option
    connect(this->add, &QPushButton::clicked, [this]()
    {
        qDebug() << "add";
        this->model->database().transaction();
        QSqlRecord _record = this->model->record();
        this->model->insertRecord(-1, _record);
    });
#endif
#if 0
    connect(this->add, SIGNAL(clicked()),
            this, SLOT(slotAddClicked()));
#endif
    //del records option
    connect(this->del, SIGNAL(clicked()),
            this, SLOT(slotDelClicked()));
    //reset all option before
    connect(this->reset, &QPushButton::clicked, [this]()
    {
        QMessageBox::warning(this, "Rollback", "All option will rollback!");
        this->model->database().rollback();
        this->model->select();
    });
    //submit all option
    connect(this->submit, &QPushButton::clicked, [this]()
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
    });
    //LineEdit Data Changed -> Slot
    connect(this->filterLine, SIGNAL(textChanged(QString)),
            this, SLOT(slotFilterChanged(QString)));
    slotModelDataChanged(QModelIndex(), QModelIndex());
}

void MyWidget04::slotDelClicked()
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


void MyWidget04::slotModelDataChanged(QModelIndex, QModelIndex)
{
    QStringList _strList;
    QSqlRecord _record;
    for (int i = 0; i < this->model->rowCount(); i++)
    {
        _record = this->model->record(i);
        for (int j = 0; j < _record.count(); j++)
        {
            QVariant _var = _record.value(j);
            if (_var.isNull())
            {
                continue;
            }
            _strList << _var.toString();
        }

    }
    qDebug() << _strList;
    //set LinedEdit`s completer
    QCompleter* _completer = new QCompleter(_strList);
    this->filterLine->setCompleter(_completer);

}


void MyWidget04::slotFilterChanged(QString p_filterStr)
{
    //If LineEdit is Empty then select all
    if (p_filterStr.isEmpty())
    {
        this->model->setFilter("");
        this->model->select();
        return;
    }
    QSqlRecord _record = this->model->record();
    QString _modelFilterStr;
    for (int i = 0; i < _record.count(); i++)
    {
        if (i != 0)
        {
            _modelFilterStr += " or ";
        }
        QString _field = _record.fieldName(i);
        //sql aaa like '%123%' the '' is very important!!!
        QString _subFilterStr = QString().sprintf("%s like '%%%s%%'", _field.toUtf8().data(), p_filterStr.toUtf8().data());
        _modelFilterStr += _subFilterStr;
    }
    qDebug() << _modelFilterStr;
    //Set model Filter
    this->model->setFilter(_modelFilterStr);
    this->model->select();
}

void MyWidget04::slotAddClicked()
{
    qDebug() << "add";
    QSqlRecord _record = this->model->record();
    this->model->insertRecord(-1, _record);
}

