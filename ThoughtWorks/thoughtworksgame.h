#ifndef THOUGHTWORKSGAME_H
#define THOUGHTWORKSGAME_H

#include <QObject>
#include <QString>
#include <QTimer>

class ThoughtWorksGame : public QObject
{
    Q_OBJECT
public:
    explicit ThoughtWorksGame(QObject *parent = 0);

signals:
    void sentSay(int num, const QString & data);//发送要输出的内容，和对应的数字
    void sentSayFinish();
public slots:
    void start(int num1, const QString & data1, int num2, const QString & data2,
               int num3, const QString & data3);//接收计算参数

protected slots:
    void say(); //报数函数
    QString getSay();//进行计算获取应该输出的结果
    QString getMoM();
private:
    int num1,num2,num3;
    QString data1,data2,data3;
    int count;//计数
    QTimer tmer;//定时器，模拟人们平均报数的时间
};

#endif // THOUGHTWORKSGAME_H
