#include "MyMainWindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    /* Menu */
    QMenuBar* menuBar = this->menuBar();//选项卡
    QMenu* menu = menuBar->addMenu("File");//选项卡条目
    QAction* open_action = menu->addAction("open", this, SLOT(fileOpen()), QKeySequence::Open);//选项卡的内容
    QAction* save_action = menu->addAction("save", this, SLOT(fileSave()), QKeySequence::Save);
    menu->addSeparator();//分隔线
    QAction* exit_action = menu->addAction("exit", this, SLOT(close()), QKeySequence::Close);


    /* toolbar */
    QToolBar* toolBar = this->addToolBar("MyToolBar");
    toolBar->addAction(open_action);
    toolBar->addAction(save_action);
    toolBar->addAction(exit_action);
    exit_action->setToolTip("close window");//在QToolBar中设置提醒

    /* status bar*/
    QStatusBar* statusBar = this->statusBar();
    //statusBar->addWidget(new QPushButton("OK"));
    statusBar->addWidget(label = new QLabel("2016-1-30"));
    label->setText("<font color = red>processing...</font>");//可以嵌入HTML


    /* centerView */
    /* 别的控件占用了之后，剩下的区域都是CentralWidget */
    centerView = new MyCenterView;
    this->setCentralWidget(centerView);

    /*systen tray icon*/
    icon = new QSystemTrayIcon;
    icon->setIcon(QIcon("../PerfCenterCpl.ico"));
    icon->setToolTip("This is a tray icon");//提醒
    icon->setContextMenu(menu);//图标的右键菜单
    icon->show();//图标显示
    //图标的信号
    connect(icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(slotActivated(QSystemTrayIcon::ActivationReason)));


}

void MyMainWindow::slotActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick)
        //Trigger单击
        //DoubleClick双击
    {
        if (this->isHidden())
        {
            this->show();
        }
        else
        {
            this->hide();
        }
    }
}



void MyMainWindow::fileOpen()
{
    QString file_name = QFileDialog::getOpenFileName();
    qDebug() << "file name is:" << file_name;
}

void MyMainWindow::fileSave()
{
    QString save_name = QFileDialog::getSaveFileName();
    qDebug() << "save name is:" << save_name;
}




int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MyMainWindow m;
    m.show();
    app.exec();
}
