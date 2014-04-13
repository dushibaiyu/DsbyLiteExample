#include "workerclass.h"
#include <QThread>
//#include <string>
//#include <QDebug>
#include "addonlist.h"

WorkerClass::WorkerClass(nzmqt::ZMQContext *context, const QString & str, QObject *parent) :
    QObject(parent),address(str),/*dbAddress(dbadd),*/
    context(context),socket(nullptr)
{
//    db = new DBClientConnection(true,0,30);
}

WorkerClass::~WorkerClass()
{
    if (socket != nullptr)
    {
        delete socket;
    }

//    delete db;
}

void WorkerClass::beginWork()
{

    //    std::string erro;
    //    if (db->connect(dbAddress.toStdString(),erro))
    //    {
    socket = context->createSocket(nzmqt::ZMQSocket::TYP_DEALER,this);
    connect(socket,&nzmqt::ZMQSocket::readyRead,this,&WorkerClass::exeData);
    socket->connectTo(address);
    //    }
    //    else
    //    {
    //        qDebug() << "connect DB ERRO:" << erro.c_str();
    //    }
}

void WorkerClass::exeData()
{
    nzmqt::ZMQMessage identity;
    nzmqt::ZMQMessage msg;
    nzmqt::ZMQMessage copied_id;
    bool ok = socket->receiveMessage(&identity);
    if (ok && socket->receiveMessage(&msg))//接收数据并判断数据是否到齐
    {
        //TODO:解序列化数据，提取出命令
        QList<QByteArray> data;
        QList<DataHandleInterface *> list = AddonList::getClass().getInterface("hello");//根据命令查找出处理此命令的所有插件
        for (int i = 0; i < list.size(); ++i)
        {
            list.at(i)->datahandle(msg.toByteArray(),data);//发送给插件处理数据
            for (int j = 0; j < data.size(); ++j)//把处理结果发送给客户端。
            {
                copied_id.copy(&identity);
                nzmqt::ZMQMessage copied_msg(data.at(j));
                socket->sendMessage(copied_id, nzmqt::ZMQSocket::SND_MORE);//告诉路由发给谁
                socket->sendMessage(copied_msg);//发送数据
            }
            data.clear();
        }
    }
}

void WorkerClass::endWork()
{
    if (socket != nullptr)
    {
        socket->close();
        delete socket;
        socket = nullptr;
    }
}
