#include "helloword.h"
#include <QDebug>
#include <QThread>

Helloword::Helloword()
{
}

void Helloword::datahandle(COMMObj::COMMObj & obj, QList<QByteArray> &data)
{
    qDebug () << QThread::currentThreadId() << "hello word";
    data.append(obj.operate().c_str());
    data.append(obj.byte_data().c_str());
}

QStringList Helloword::getCommod() const
{
    return QStringList() << "hello";
}
