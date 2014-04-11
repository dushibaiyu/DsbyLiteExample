#include "helloword.h"
#include <QDebug>

Helloword::Helloword()
{
}

bool Helloword::datahandle(const QByteArray &data, QList<QByteArray> &sdata)
{
    qDebug () << data << "hello word";
    sdata.append("hello");
    sdata.append("word");
    return true;
}
