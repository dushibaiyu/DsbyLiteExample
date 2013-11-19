#ifndef FTPCUTDOWN_H
#define FTPCUTDOWN_H

#include <QObject>
#include <QtCore>
#include <QtNetwork>

class ftpCutDown : public QObject
{
    Q_OBJECT
public:
    explicit ftpCutDown(QUrl url,QObject *parent = 0);
    qint64 getFileSize();
    void startDownload(qint64 start =0, qint64 end=-1);

signals:
    void downFinish();
public slots:
    QByteArray  & getData();

private:
    QNetworkAccessManager m_Qnam;
    QNetworkReply * m_Reply;
    qint64 theLast;
    QByteArray data;
    QUrl url;
};

#endif // FTPCUTDOWN_H
