#include "thoughtworksgame.h"

ThoughtWorksGame::ThoughtWorksGame(QObject *parent) :
    QObject(parent),count(0)
{
    connect(&tmer,&QTimer::timeout,this,&ThoughtWorksGame::say);
}

void ThoughtWorksGame::start(int num1, const QString &data1, int num2, const QString &data2,
                        int num3, const QString &data3)
{
    this->num1 = num1;
    this->num2 = num2;
    this->num3 = num3;
    this->data1 = data1;
    this->data2 = data2;
    this->data3 = data3;
    tmer.start(700);
}

inline void ThoughtWorksGame::say()
{
    count ++;
    if (count >= 100)
    {
        emit this->sentSayFinish();
        count = 0;
        tmer.stop();
    }
    else
    {
        emit this->sentSay(count,getSay());
    }
}

inline QString ThoughtWorksGame::getSay()
{
    int tmp = count %10;
    if (tmp == num1 || (num1 * 10) == (count-tmp)) //判断是否这个数包含特殊数字1
    {
        return data1;
    }
    return getMoM();
}

QString ThoughtWorksGame::getMoM()
{
    QString data;
    if (count % num1 == 0)
    {
        data = data1;
    }
    if (count % num2 == 0)
    {
        data += data2;
    }
    if (count % num3 == 0)
    {
        data += data3;
    }
    if (data.isEmpty())
    {
        data.setNum(count);
    }
    return data;
}
