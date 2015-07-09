#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "ImageWrapper.h"
#include <QTime>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <zxing/ReaderException.h>
#include <zxing/multi/GenericMultipleBarcodeReader.h>
#include <zxing/MultiFormatReader.h>
#include <zxing/Binarizer.h>
#include <zxing/BinaryBitmap.h>
#include <zxing/DecodeHints.h>
#include <zxing/common/GlobalHistogramBinarizer.h>

using namespace zxing;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,tr("打开图片"),QString(),tr("Images (*.png *.jpg *.bmp *.tiff);"));
    this->ui->textEdit->clear();
    if (path.isEmpty()) return;
    this->ui->lineEdit->setText(path);
    QImage img;
    if (!img.load(path) ) {
        this->ui->textEdit->append(tr("打开图片文件失败！"));
    } else {
        QImage tp = img.scaled(721,411);
        this->ui->label->setPixmap(QPixmap::fromImage(tp));
        qrImage(img);
    }
}

void MainWindow::qrImage(QImage img)
{
      QTime tm;
    try {
        this->ui->textEdit->append(tr("开始解析图形中的所有条码和二维码："));
        tm.start();
        std::vector<Ref<Result> > data;
        Ref<LuminanceSource> source(new ImageWrapper(img));
        Ref<Binarizer> binarizer(new GlobalHistogramBinarizer(source));
        Ref<BinaryBitmap> binary(new BinaryBitmap(binarizer));
        MultiFormatReader delegate;
        multi::GenericMultipleBarcodeReader reader(delegate);
        DecodeHints hints(DecodeHints::DEFAULT_HINT);
        hints.setTryHarder(true);
        data = reader.decodeMultiple(binary, hints);
        int s = tm.elapsed();
        for (size_t i = 0;  i < data.size(); ++i) {
            Ref<Result> result = data.at(i);
            this->ui->textEdit->append(
                        tr("type：%1 ， Code Data：%2 ")
                                       .arg(BarcodeFormat::barcodeFormatNames[result->getBarcodeFormat().value])
                    .arg(result->getText()->getText().c_str()));
        }
        this->ui->textEdit->append(tr("一共用时：%1 ms \n").arg(s));
    }
    catch(zxing::Exception& e)
    {
        tm.elapsed();
        this->ui->textEdit->setPlainText(tr("解码失败：%1 \n").arg(e.what()));
        return;
    }
}

