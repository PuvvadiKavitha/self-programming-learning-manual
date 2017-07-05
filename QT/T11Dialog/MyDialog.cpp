#include "MyDialog.h"




MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent)
{
    QPushButton *button = new QPushButton("clicked", this);
    connect(button, SIGNAL(clicked()), this, SLOT(slotClickedButton()));
}

void MyDialog::slotClickedButton()
{
#if 0
    QDialog* dlg = new QDialog;
    QPushButton *button = new QPushButton("Exit", dlg);
    //connect(button, SIGNAL(clicked()), dlg, SLOT(accept()));
    connect(button, SIGNAL(clicked()), dlg, SLOT(reject()));
    //dlg->show();
    int ret = dlg->exec();
    // 在模块对话框中，exec有自己的消息循环，并且把app的消息循环接管了
    // 如果Dialog是通过exec来显示，那么可以通过accept或者reject来关闭窗口
    // 如果Dialog是通过show来显示，那么可以通过close来关闭窗口，这个和QWidget一样的

    if (ret == QDialog::Accepted)
    {
        qDebug() << "Accepted";
    }
    if (ret == QDialog::Rejected)
    {
        qDebug() << "Rejected";
    }
#endif
#if 0
    //保存文件对话框
    QString strFilename = QFileDialog::getSaveFileName(nullptr,
                                                       "Select file for save",
                                                       strDir,
                                                       "Png file (*.png)");

#endif

#if 0
    //打开文件对话框
    QString strFilename = QFileDialog::getOpenFileName(nullptr,
                                                       "Select file for save",
                                                       strDir,
                                                       "Png file (*.png)");
    QString strFilename = QFileDialog::getOpenFileName();//不指定参数也可以
#endif
    //打开多个文件即列表QStringList strList = QFileDialog::getOpenFileNames();
#if 0
    //选择文件夹
    QString strFilename = QFileDialog::getExistingDirectory();
    if (strFilename.isEmpty())
    {
        qDebug() << "select none";
        return;
    }

    qDebug() << strFilename;
    QFileInfo file_info(strFilename);//得到文件的信息
    strDir = file_info.filePath();//得到文件的路径信息
#endif
#if 0
    QColorDialog color;
    color.exec();
    QColor c = color.selectedColor();
#endif

#if 0
    QFontDialog font;
    font.exec();
    QFont f = font.selectedFont();
#endif

#if 0
    //QMessageBox::warning(this, "Waring", "!!!!");//警告
    //QMessageBox::information(this, "info", "do....");//普通信息
    //QMessageBox::critical(this, "Error", "Error");//致命错误
    int ret = QMessageBox::question(this, "question", "real do???",//提问对话框
                                    QMessageBox::YesAll | QMessageBox::NoAll
                                    | QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes)
    {
        qDebug() << "Yes";
    }
    if (ret == QMessageBox::No)
    {
        qDebug() << "No";
    }
#endif
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MyDialog d;
    //d.show();//非模块对话框
    d.exec();//模块对话框，只有前面的对话框关闭之后，后面的才可以执行
    app.exec();
}


