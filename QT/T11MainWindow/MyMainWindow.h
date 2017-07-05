#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QSystemTrayIcon>

#include <QDebug>

#include "MyCenterView.h"
class MyMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QLabel* label;
    MyCenterView* centerView;
    QSystemTrayIcon* icon;
    explicit MyMainWindow(QWidget *parent = 0);

signals:

public slots:
    void fileOpen();
    void fileSave();
    void slotActivated(QSystemTrayIcon::ActivationReason);

};

#endif // MYMAINWINDOW_H
