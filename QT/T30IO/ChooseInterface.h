#ifndef CHOOSEINTERFACE_H
#define CHOOSEINTERFACE_H

#include <QDialog>
#include <QNetworkInterface>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
class ChooseInterface : public QDialog
{
    Q_OBJECT
public:
    explicit ChooseInterface(QWidget *parent = 0);
    QComboBox* ipCom;//选择ip
    QString  selectIP;//储存选择的ip
    QLineEdit* editPort;//选择端口
    int port;//储存端口
signals:

public slots:
    //选择ip
    void slotCurrentIndexChanged(QString);
    //按钮点击
    void slotOK();

};

#endif // CHOOSEINTERFACE_H
