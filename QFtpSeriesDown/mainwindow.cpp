#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ftp.setTransferMode(QFtp::Passive);
    ftp.connectToHost("127.0.0.1");
    ftp.login("test","test");
    ftp.rawCommand("SIZE test.txt");//得到文件大小
    ftp.get("test.txt",nullptr,2000);
    connect(&ftp,&QFtp::rawCommandReply,[this](int a,const QString & str){
        this->ui->textBrowser->append(str);
    });//执行命令的结果
    connect(&ftp,&QFtp::readyRead,[this](){
        this->ui->textBrowser->append(this->ftp.readAll());
    });//显示下载的内容

}

MainWindow::~MainWindow()
{
    delete ui;
}
