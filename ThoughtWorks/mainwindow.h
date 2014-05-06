#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void sentPar(int num1, const QString &data1, int num2, const QString &data2,
                 int num3, const QString &data3);
protected slots:
    void on_BuStart_clicked();
protected:
    void initUI();//初始化UI
    void connectSlots();//链接信号槽

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
