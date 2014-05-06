#include "ftpcutdown.h"

ftpCutDown::ftpCutDown(QUrl url, QObject *parent) :
    url(url), QObject(parent)
{
    theLast = 0;
}

qint64 ftpCutDown::getFileSize()
{
    QNetworkAccessManager manager;
    //qDebug() << "Getting the file size...";
    QEventLoop loop;
    //发出请求，获取目标地址的头部信息
    QNetworkReply *reply = manager.head(QNetworkRequest(url));
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()), Qt::DirectConnection);
    loop.exec();
    QVariant var = reply->header(QNetworkRequest::ContentLengthHeader);
    reply->deleteLater();
    qint64 size = var.toLongLong();
    //qDebug() << "The file size is: " << size;
    return size;
}

void ftpCutDown::startDownload(qint64 start, qint64 end)
{
       //根据HTTP协议，写入RANGE头部，说明请求文件的范围
       QNetworkRequest qheader;
       qheader.setUrl(url);
       QString range;
       range.sprintf("Bytes=%lld-%lld", start, end);
       qheader.setRawHeader("Range", range.toLocal8Bit());

       //开始下载
       m_Reply = m_Qnam.get(QNetworkRequest(qheader));
       connect(m_Reply, &QNetworkReply::finished,[this](){
            this->data = this->m_Reply->readAll();
           emit this->downFinish();
       });
}

QByteArray & ftpCutDown::getData()
{
    return this->data;
}

