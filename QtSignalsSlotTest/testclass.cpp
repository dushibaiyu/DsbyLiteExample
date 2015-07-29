#include "testclass.h"
#include <QDebug>
#include <QThread>

TestClass::TestClass(QObject *parent) : QObject(parent),tt(new ThreadTest)
{
    // auto模式，同一线程直接模式，直接调用，有返回值
    connect(this,&TestClass::testInt1,this,&TestClass::int1);

    //队列模式，异步调用，无返回值
    connect(this,&TestClass::testInt2,this,&TestClass::int2,Qt::QueuedConnection);

    //auto模式，同一线程直接模式，直接调用，有返回值
    connect(this,&TestClass::teestString1,this,&TestClass::string1);

    //队列模式，异步调用，无返回值
    connect(this,&TestClass::teestString2,this,&TestClass::string2,Qt::QueuedConnection);

    //mstring2 是队列连接，异步调用，其返回值无效，mstring1直接连接，直接调用，返回其返回值
    connect(this,&TestClass::teestMString,this,&TestClass::mstring2,Qt::QueuedConnection);
    connect(this,&TestClass::teestMString,this,&TestClass::mstring1);

    //两个都是直接连接，都是直接调用，返回值都有效，但是最后连接的mstring2，则返回最后的值
    connect(this,&TestClass::teestMString1,this,&TestClass::mstring1);
    connect(this,&TestClass::teestMString1,this,&TestClass::mstring2);
    //两个都是直接连接，都是直接调用，返回值都有效，但是最后连接的mstring1，则返回最后的值
    connect(this,&TestClass::teestMString2,this,&TestClass::mstring2);
    connect(this,&TestClass::teestMString2,this,&TestClass::mstring1);


    QThread * th = new QThread(tt);
    tt->moveToThread(th);
    // 不同线程，阻塞模式，同步调用，有返回值
    connect(this,&TestClass::threadString1,tt,&ThreadTest::string1,Qt::BlockingQueuedConnection);

    //auto模式，不同线程则为队列模式，异步调用，无返回值，且复制所有参数
    connect(this,&TestClass::threadString3,tt,&ThreadTest::string2);

     //mstring1 是队列连接，异步调用，其返回值无效，mstring2阻塞连接，直接调用，返回其返回值
    connect(this,&TestClass::threadString,tt,&ThreadTest::mstring1);
    connect(this,&TestClass::threadString,tt,&ThreadTest::mstring2,Qt::BlockingQueuedConnection);

    // 值，不确定
    connect(this,&TestClass::txstrings1,tt,&ThreadTest::xstring1);
    connect(this,&TestClass::txstrings1,this,&TestClass::xstring);
    // 值已变
    connect(this,&TestClass::txstrings2,tt,&ThreadTest::xstring3,Qt::BlockingQueuedConnection);
    connect(this,&TestClass::txstrings2,this,&TestClass::xstring);

    th->start();
}
TestClass::~TestClass()
{
    tt->thread()->quit();
    tt->thread()->wait(300);
    delete tt;
}

int TestClass::int1()
{
    return 1;
}

int TestClass::int2()
{
    return 2;
}

QString TestClass::string1(const QString & str)
{
    qDebug() << "\t\tTestClass::string1 : " << &str << "\n";
    return str;
}

QString TestClass::string2(const QString & str)
{
    qDebug() << "\t\tTestClass::string2 : " << &str << "\n";
    return str;
}

QString TestClass::mstring1()
{
    return QString("TestClass::mstring1");
}

QString TestClass::mstring2()
{
    return QString("TestClass::mstring2");
}

QString TestClass::xstring1(QString *str)
{
    qDebug() << "\t\tTestClass::xstring1： str = " << *str;
    *str = "TestClass::xstring1";
    return *str;
}

QString TestClass::xstring(QString * str)
{
    qDebug() << "\t\tTestClass::xstring： str = " << *str;
    return *str;
}

QString TestClass::xstring3(QString * str)
{
    qDebug() << "\t\tTestClass::xstring3： str = " << *str;
    *str = "TestClass::xstring3";
    return *str;
}

ThreadTest::ThreadTest(QObject *parent):QObject(parent)
{}

QString ThreadTest::string1(const QString & str)
{
    qDebug() << "\t\tThreadTest::string1 : " << &str << "\n";
    return str;
}

QString ThreadTest::string2(const QString & str)
{
    qDebug() << "\t\tThreadTest::string2 : " << &str << "\n";
    return str;
}

QString ThreadTest::mstring1()
{
    return QString("ThreadTest::mstring1");
}

QString ThreadTest::mstring2()
{
    return QString("ThreadTest::mstring2");
}

QString ThreadTest::xstring1(QString * str)
{
    qDebug() << "\t\tThreadTest::xstring1： str = " << *str;
    *str = "ThreadTest::xstring1";
    return *str;
}

QString ThreadTest::xstring3(QString * str)
{
    qDebug() << "\t\tThreadTest::xstring3： str = " << *str;
    *str = "ThreadTest::xstring3";
    return *str;
}
