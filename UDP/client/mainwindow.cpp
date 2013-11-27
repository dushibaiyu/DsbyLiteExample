#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udp = new QUdpSocket(this);
    ui->ip->setText("127.0.0.1");
    ui->port->setText("5432");
    connect(udp,&QUdpSocket::readyRead,[&](){
        QHostAddress host;
        quint16 port;
        char  temp[2048];
        qDebug() << udp->readDatagram(temp,2048,&host,&port);
        ui->textBrowser->append("接受数据：" + host.toString() + ":" + QString::number(port));
        ui->textBrowser->append(temp);
    });
}

MainWindow::~MainWindow()
{
    udp->deleteLater();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (!ui->data->text().isEmpty() && ! ui->ip->text().isNull() && ! ui->port->text().isNull())
    {
//        QString temp(ui->data->text());
        int i = udp->writeDatagram(ui->data->text().toUtf8(),QHostAddress(ui->ip->text()),ui->port->text().toInt());
        if (i <= 0)
        {
            ui->textBrowser->append("发送失败");
        }
        else
        {
            ui->textBrowser->append( "发送成功：" + ui->ip->text()+ ":" + ui->port->text());
            ui->textBrowser->append(ui->data->text());
        }
    }
    else
    {
        ui->textBrowser->append("请输入完数据。");
    }
}

