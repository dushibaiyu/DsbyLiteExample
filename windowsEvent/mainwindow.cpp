#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    obj.setParent(this);
    ui->textEdit->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject * obj, QEvent * e)
{
  if (obj == this->ui->textEdit) {
       if (e->type() == QEvent::KeyPress) {
            QKeyEvent* ev = static_cast<QKeyEvent*>(e);

            if (ev->key() == Qt::Key_A) {

                qDebug() << "MainWindow::eventFilter : A";

                return true;

            }

        }
    }

    return false;

}

void  MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    qDebug() << " MainWindow::mouseReleaseEvent";
}

void MainWindow::on_pushButton_clicked()
{
    MyEvent * ev = new MyEvent;
    QCoreApplication::postEvent(&obj,ev);
    ev = new MyEvent;
    QCoreApplication::postEvent(this->ui->widget_2,ev);
}
