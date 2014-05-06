#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include "thoughtworksgame.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    initUI();
    connectSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    for (int i = 1; i< 10; ++i)
    {
        this->ui->cBoxNum1->addItem(QString::number(i));
        this->ui->cBoxNum2->addItem(QString::number(i));
        this->ui->cBoxNum3->addItem(QString::number(i));
    }
    this->ui->EditNum1->setText("Fizz");
    this->ui->EditNum2->setText("Buzz");
    this->ui->EditNum3->setText("Whizz");
    int num1 = qrand()%9;
    while (num1 == 0 )
    {
        num1 = qrand()%9;
    }
    this->ui->cBoxNum1->setCurrentIndex(num1);
    int num2 = qrand()%9;
    while (num2 == num1 || num2 == 0)
    {
        num2 = qrand()%9;
    }
    this->ui->cBoxNum2->setCurrentIndex(num2);
    int num3 = qrand()%9;
    while (num3 == num1 || num3 == num2 || num3 == 0)
    {
        num3 = qrand()%9;
    }
    this->ui->cBoxNum3->setCurrentIndex(num3);
}

void MainWindow::connectSlots()
{
    ThoughtWorksGame * gm = new ThoughtWorksGame(this);
    connect(this,&MainWindow::sentPar,gm, &ThoughtWorksGame::start);
    connect(gm,&ThoughtWorksGame::sentSay,[&](int num, const QString & data){
        this->ui->textEdit->append(tr("数字为：%1；应输出：%2").arg(num).arg(data));
    });
    connect(gm,&ThoughtWorksGame::sentSayFinish,[&](){
        this->ui->BuStart->setEnabled(true);
    });
}

void MainWindow::on_BuStart_clicked()
{
    emit this->sentPar(this->ui->cBoxNum1->currentIndex() + 1, this->ui->EditNum1->text(),
                       this->ui->cBoxNum2->currentIndex() + 1, this->ui->EditNum2->text(),
                       this->ui->cBoxNum3->currentIndex() + 1, this->ui->EditNum3->text());
    this->ui->textEdit->clear();
    this->ui->BuStart->setEnabled(false);
}
