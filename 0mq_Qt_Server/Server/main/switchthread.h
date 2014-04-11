#ifndef SWITCHTHREAD_H
#define SWITCHTHREAD_H


/*
 *0mq实现  [ XREQ ]<---->[ XREP <----> XREQ <----> XREQ ] 模式的中转设备
 * 纯异步操作
 *XREQ : DEALER
 *XREP : ROUTER
 * 采用公平队列算法自动分配到不同的处理端
 * 全部采用TCP协议，方便以后动态增添服务器
 * 继承QThread实现，单独一个线程处理。
*/

#include <QThread>
#include <zmq.hpp>

class SwitchThread : public QThread
{
    Q_OBJECT
public:
    explicit SwitchThread(QObject *parent = 0);

signals:

public slots:

protected:
    void run();
};

#endif // SWITCHTHREAD_H
