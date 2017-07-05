#include <QApplication>
#include <QLineEdit>
#include <QCompleter>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget w;
    w.setWindowTitle("Hello World");

    QLineEdit edit;
    edit.setParent(&w);
    edit.text();
    //enum EchoMode { Normal, NoEcho, Password, PasswordEchoOnEdit };
    edit.setEchoMode(QLineEdit::Normal);
    edit.setPlaceholderText("please input password:");

    QCompleter com(QStringList() << "saf" << "123" << "5sf");

    /*enum MatchFlag {
    MatchExactly = 0,
    MatchContains = 1,
    MatchStartsWith = 2,
    MatchEndsWith = 3,
    MatchRegExp = 4,
    MatchWildcard = 5,
    MatchFixedString = 8,
    MatchCaseSensitive = 16,
    MatchWrap = 32,
    MatchRecursive = 64
    };
Q_DECLARE_FLAGS(MatchFlags, MatchFlag)*/


    com.setFilterMode(Qt::MatchContains);
    edit.setCompleter(&com);




    w.show();
    return app.exec();
}

