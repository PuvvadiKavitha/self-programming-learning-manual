#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setXY(int a, int b);
    Dialog* operator ++();
    Dialog* operator ++(int);
    Dialog* operator +(const Dialog& dig);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    int x;
    int y;
};

#endif // DIALOG_H
