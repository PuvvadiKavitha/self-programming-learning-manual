#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    QPushButton *button;
    QLineEdit *edit;

    explicit MyWidget(QWidget *parent = 0);
    bool event(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    //void mouseDoubleClickEvent(QMouseEvent *);

    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

    void closeEvent(QCloseEvent *);
    void showEvent(QShowEvent *);
    void hideEvent(QHideEvent *);

    void paintEvent(QPaintEvent *);

signals:

public slots:
    void ButtonClicked();

};

#endif // MYWIDGET_H
