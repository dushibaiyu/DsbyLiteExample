#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QString>

class ThreadTest;
class QThread;

class TestClass : public QObject
{
    Q_OBJECT
public:
    explicit TestClass(QObject *parent = 0);
    ~TestClass();
signals:
    int testInt1();//自动连接，直接连接
    int testInt2(); //队列连接
    QString teestString1(const QString & str); //直接连接
    QString teestString2(const QString & str); //队列连接
    QString teestMString1(); // mstring 1 在前，mstring 2 在后
    QString teestMString2(); // mstring 2 在前，mstring 1 在后
    QString teestMString(); // mstring 2 队列，mstring 1 直接

    QString teestString(QString * str);

    QString txstrings1(QString & str);
    QString txstrings2(QString * str);

    QString threadString();// mstring 1 队列，mstring 2 阻塞
    QString threadString1(const QString & str); // 阻塞
    QString threadString3(const QString & str); //自动模式，也就是队列

public slots:
    int int1();
    int int2();
    QString string1(const QString & str);
    QString string2(const QString & str);
    QString mstring1();
    QString mstring2();

    QString xstring(QString * str);

private:
    ThreadTest * tt;
};

class ThreadTest : public QObject
{
    Q_OBJECT
public:
    explicit ThreadTest(QObject *parent = 0);

public slots:
    QString string1(const QString & str);
    QString string2(const QString & str);
    QString mstring1();
    QString mstring2();

    QString xstring1(QString & str);
    QString xstring3(QString * str);
};

#endif // TESTCLASS_H
