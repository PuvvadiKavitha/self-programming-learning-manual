#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>
class MyDialog : public QDialog
{
    Q_OBJECT
public:
    QString strDir;
    explicit MyDialog(QWidget *parent = 0);

signals:

public slots:
    void slotClickedButton();

};

#endif // MYDIALOG_H
