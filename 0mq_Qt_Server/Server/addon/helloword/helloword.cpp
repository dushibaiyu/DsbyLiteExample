#include "helloword.h"
#include <QDebug>

Helloword::Helloword()
{
}

void Helloword::datahandle(const QByteArray &data, QList<QByteArray> &sdata)
{
    qDebug () << data << "hello word";
    sdata.append("hello");
    sdata.append("word");
}

QStringList Helloword::getCommod() const
{
    return QStringList() << "hello";
}
