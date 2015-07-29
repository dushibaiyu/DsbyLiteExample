#include <QCoreApplication>
#include <QDebug>
#include "testclass.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << int();
    TestClass tset;

    qDebug() << "testInt1 : " << tset.testInt1() << "\n";

    qDebug() << "testInt2 : " << tset.testInt2() << "\n";

    QString str = QString("tset.teestString1");
    qDebug() << "\tteestString1 &str = " << &str;
    qDebug() << "teestString1 : " << tset.teestString1(str) << "\n";

    str = QString("tset.teestString2");
    qDebug() << "\tteestString1 &str = " << &str;
    qDebug() << "teestString2 : " << tset.teestString2(str) << "\n";

    qDebug() << "teestMString1 : " << tset.teestMString1() << "\n";

    qDebug() << "teestMString2 : " << tset.teestMString2() << "\n";

    qDebug() << "teestMString : " << tset.teestMString() << "\n";

    qDebug() << "threadString : " << tset.threadString() << "\n";

    str = QString("tset.threadString1");
    qDebug() << "\tthreadString1 &str = " << &str;
    qDebug() << "threadString1 : " << tset.threadString1(str) << "\n";

    str = QString("tset.threadString3");
    qDebug() << "\tthreadString3 &str = " << &str;
    qDebug() << "threadString3 : " << tset.threadString3(str) << "\n";

    str = QString("tset.txstrings2");
    qDebug() << "\ttxstrings2 &str = " << &str;
    qDebug() << "txstrings2 : " << tset.txstrings2(&str) << "\n";

    str = QString("tset.txstrings1");
    qDebug() << "\txstrings1 &str = " << &str;
    qDebug() << "txstrings1 : " << tset.txstrings1(str) << "\n";

    QThread::msleep(500);
    qDebug() << "last str : " << str;

    return a.exec();
}
