#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QCompleter>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget w;

    QPushButton button;
    button.setText("Button");
    QLineEdit edit;
    edit.setPlaceholderText("Please input text:");
#if 0
    QHBoxLayout HLayout;
    HLayout.addStretch(1);
    HLayout.addWidget(&button);
    //HLayout.addStretch(1);
    HLayout.addSpacing(10);
    HLayout.addWidget(&edit);
    HLayout.addStretch(1);
    w.show();
    w.setLayout(&HLayout);
#endif

#if 0
    QVBoxLayout VLayout;
    VLayout.addStretch(1);
    VLayout.addWidget(&button);
    VLayout.addSpacing(100);
    VLayout.addWidget(&edit);
    VLayout.addStretch(1);
    w.setLayout(&VLayout);
    w.show();
#endif
    QGridLayout QGLayout;
    QLineEdit *username;
    QLineEdit *password;
    QGLayout.setColumnStretch(3, 1);
    QGLayout.setColumnStretch(0, 1);
    QGLayout.setRowStretch(0, 1);
    QGLayout.setRowStretch(4, 1);

    QGLayout.addWidget(new QLabel("Username:"), 1, 1);
    QGLayout.addWidget(username = new QLineEdit(), 1, 2);
    QGLayout.addWidget(new QLabel("Password:"), 2, 1);
    QGLayout.addWidget(password = new QLineEdit(), 2, 2);
    username->setPlaceholderText("please input username");

    QCompleter com(QStringList() << "872785786");
    com.setFilterMode(Qt::MatchContains);
    username->setCompleter(&com);
    password->setEchoMode(QLineEdit::Password);
    password->setPlaceholderText("please input password");

    QHBoxLayout *HLayout;
    QPushButton *cancel;
    QGLayout.addLayout(HLayout = new QHBoxLayout(), 3, 2);
    HLayout->addStretch(1);
    HLayout->addWidget(cancel = new QPushButton("Cancel"));
    HLayout->addWidget(new QPushButton("Login"));
    HLayout->addStretch(1);
    QObject::connect(cancel, SIGNAL(clicked()), &w, SLOT(close()));

    w.setWindowTitle("Login");
    w.show();
    w.setLayout(&QGLayout);


    return app.exec();
}
