#include "MyWidget.h"
#include <QApplication>
#include <QCompleter>
#include <QDebug>
#include <QPixmap>

#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QTextEdit>
#include <QTextBrowser>
#include <QGroupBox>
#include <QSlider>
#include <QSpinBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QLCDNumber>

#include <QVBoxLayout>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *Layout = new QVBoxLayout(this);


    QLabel *label;
    Layout->addWidget(label = new QLabel("<a href = www.baidu.com>www.baidu.com</a>"));
    label->setPixmap(QPixmap("../aaa.png"));
    //处理信号
    QObject::connect(label, &QLabel::linkActivated, [](QString str){
        qDebug() << str;
    });


    QPushButton *button;
    Layout->addWidget(button = new QPushButton("Button"));
    button->setStyleSheet("QPushButton {font:bold 15px; color:red}");
    connect(button, &QPushButton::clicked, [](bool v){
        qDebug() << v;
    });



    QRadioButton *radio;
    Layout->addWidget(radio = new QRadioButton("Radio"));
    radio->setStyleSheet("QRadioButton {font:bold 15px; color:red}");
    connect(radio, &QRadioButton::clicked, [](bool v){
        qDebug() << v;
    });

    Layout->addWidget(new QCheckBox("check box"));

    QComboBox *com;
    Layout->addWidget(com = new QComboBox());
    com->setEditable(true);
    QCompleter *completer;
    com->setCompleter(completer = new QCompleter(QStringList() << "aaa" << "chenghzhi" << "jiayu"));
    completer->setFilterMode(Qt::MatchContains);
    //com->setCompleter(new QCompleter(com->model()));
    com->addItem("Item1");
    com->addItem("Item2");
    connect(com, SIGNAL(currentTextChanged(QString)), this, SLOT(slotComBoxIndexChanged(QString)));



    QTextEdit *edit;
    Layout->addWidget(edit = new QTextEdit());
    edit->setText("<table border = 1><tr><th>head1</th><th>head2</th></tr>"
                  "<tr><td>value1</td><td>value2</td></tr>"
                  "<tr><td>value3</td><td>value4</td></tr>"
                  "</table><br>"
                  "<img src = ../aaa.png></img>");
     _edit = edit;
    connect(edit, &QTextEdit::textChanged, [&](){
        qDebug() << _edit->toPlainText();
    });
    edit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    edit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QGroupBox *group;
    QHBoxLayout *hBoxLayout;
    Layout->addWidget(group = new QGroupBox("Group Items"));
    group->setLayout(hBoxLayout = new QHBoxLayout);
    hBoxLayout->addWidget(new QPushButton("A"));
    hBoxLayout->addWidget(new QPushButton("B"));

    QSlider *slider;
    Layout->addWidget(slider = new QSlider(Qt::Horizontal));
    slider->setMaximum(100);
    slider->setMinimum(0);
    //label->setText((QString)slider->value());
    QSpinBox *spinbox;
    Layout->addWidget(spinbox = new QSpinBox());
    spinbox->setMaximum(100);
    spinbox->setMinimum(0);
    connect(slider, SIGNAL(valueChanged(int)), spinbox, SLOT(setValue(int)));
    connect(spinbox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

    //不常用
    Layout->addWidget(new QDateEdit());
    Layout->addWidget(new QTimeEdit());
    Layout->addWidget(new QDateTimeEdit());

    QLCDNumber *LCD;
    Layout->addWidget(LCD = new QLCDNumber);
    LCD->display(12345);
    LCD->setMode(QLCDNumber::Hex);
    LCD->setSegmentStyle(QLCDNumber::Flat);

}

void MyWidget::slotComBoxIndexChanged(const QString &str)
{
    qDebug() << "slotComBoxIndexChanged" << str;
}


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MyWidget w;
    w.show();
    return app.exec();
}
