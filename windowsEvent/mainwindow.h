#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include "myobject.h"

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool eventFilter(QObject * obj, QEvent * e);
protected:
    void mouseReleaseEvent(QMouseEvent *);

    void customEvent(QEvent * e) {
         qDebug() << "MainWindow::customEvent";
        if (e->type() == MyEvent::etype) {
            qDebug() << "MainWindow::customEvent";
        } else {
            QWidget::event(e);
        }
    }

private slots:
    void on_pushButton_clicked();

private:
    MyObject obj;
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
