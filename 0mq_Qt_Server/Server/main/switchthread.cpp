#include "switchthread.h"
#include "configclass.h"


SwitchThread::SwitchThread(QObject *parent) :
    QThread(parent)
{
}

void SwitchThread::run()
{
    zmq::context_t context(1);

    //  创建前端监听端口
    zmq::socket_t frontend (context, ZMQ_ROUTER);
    frontend.bind(ConfigClass::getClass().outBind.toStdString().c_str()); //客户端连接端口

    //  创建后端监听端口
    zmq::socket_t backend (context, ZMQ_DEALER);
    zmq_bind (backend, ConfigClass::getClass().inBind.toStdString().c_str()); //服务端处理连接端口

    //  开始中转，采用0mq预定义设备
    zmq_device (ZMQ_QUEUE, frontend, backend);
}


