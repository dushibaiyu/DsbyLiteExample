#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udp = new QUdpSocket(this);
    connect(udp,&QUdpSocket::readyRead,[&](){
        char  temp[2048];
        qDebug() << udp->readDatagram(temp,2048,&host,&port);
        ui->textBrowser->append("接受数据：" + host.toString() + ":" + QString::number(port));
        ui->textBrowser->append(temp);
        //收到的数据返回去
        udp->writeDatagram(QString(temp).toUtf8(),host,port);
    });
    ui->port->setText("5432");
}

MainWindow::~MainWindow()
{
    udp->deleteLater();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if ( !ui->port->text().isNull())
    {
        bool tmp = udp->bind(QHostAddress::Any,ui->port->text().toInt());
       if (!tmp)
       {
           ui->textBrowser->append("监听失败！");
       }
       else
       {
           ui->textBrowser->append("监听成功！");
       }

    }
    else
    {
        ui->textBrowser->append("请输入完数据。");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if (!host.isNull() && !ui->lineEdit->text().isNull())
    {
        int i = udp->writeDatagram(ui->lineEdit->text().toUtf8(),host,port);
        if (i <= 0)
        {
            ui->textBrowser->append("发送失败");
        }
        else
        {
            ui->textBrowser->append( "发送成功：" + host.toString() + ":" + QString::number(port));
            ui->textBrowser->append(ui->lineEdit->text());
        }
    }
}
