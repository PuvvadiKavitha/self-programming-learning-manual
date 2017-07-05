#include "MyWidget06.h"
#include <QSqlQuery>
#include <QVBoxLayout>

MyWidget06::MyWidget06(QWidget *parent) :
    QWidget(parent)
{
    this->model = new QSqlQueryModel;
    this->view = new QTableView(this);
    this->view->setModel(this->model);

    //Use Sql directly
    this->model->setQuery("select * from tuser");
    QVBoxLayout* lay = new QVBoxLayout(this);
    lay->addWidget(this->view);

}
