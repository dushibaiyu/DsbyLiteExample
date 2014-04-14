#ifndef CONTROLWORKER_H
#define CONTROLWORKER_H

/*
 *  任务调度类
 * 新建和管理工作类
*/

#include <QObject>
#include <QList>
#include "workerclass.h"

class ControlWorker : public QObject
{
    Q_OBJECT
public:
    explicit ControlWorker(QObject *parent = 0);
    ~ControlWorker();
signals:
    void startWorker();//工作类开始信号
    void endWorker();//工作类释放信号
public slots:
    //开始处理接收数据：interval：zmq轮训间隔时间,单位毫秒；timeout：轮训的超时时间
    void beginWork(int interval = 50, long timeout = 0);

    void setWork(int size);//开启多少个工作类，每个类一个线程。

    void endAllWork();//结束所有处理
private:
    bool istarted;//是否再接受数据
    QList<WorkerClass *> wklist;//工作着列表
    nzmqt::ZMQContext * context;
};

#endif // CONTROLWORKER_H
