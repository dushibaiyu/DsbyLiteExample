#include "workerclass.h"
#include <QThread>
//#include <string>
#include <QDebug>
#include "addonlist.h"
#include "configclass.h"

WorkerClass::WorkerClass(nzmqt::ZMQContext *context, /*const QString &dbadd,*/ QObject *parent) :
    QObject(parent),context(context),socket(nullptr),isOk(false)
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
    socket->connectTo(ConfigClass::getClass().conAddress);
    //    }
    //    else
    //    {
    //        qDebug() << "connect DB ERRO:" << erro.c_str();
    //    }
}

void WorkerClass::exeData()
{
//    nzmqt::ZMQMessage identity;
    isOk = false;
    nzmqt::ZMQMessage msg;
    nzmqt::ZMQMessage copied_id;
    bool ok = socket->receiveMessage(&identity);
    if (ok && socket->receiveMessage(&msg))//接收数据并判断数据是否到齐
    {
        isOk = true;
        COMMObj::COMMObj obj;
        if (!COMMObj_Analyze(msg.toByteArray(),obj))
        {
            return ;
        }
        QList<QByteArray> data;
        //根据命令查找出处理此命令的所有插件
        QList<DataHandleInterface *> list = AddonList::getClass().getInterface(QString::fromStdString(obj.operate()));
        for (int i = 0; i < list.size(); ++i)
        {
            list.at(i)->datahandle(obj,data,std::bind(&WorkerClass::sentMessage,this));//发送给插件处理数据
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
    isOk = false;
}

void WorkerClass::sentMessage(const QByteArray &data)
{
    if (!isOk) return;
    nzmqt::ZMQMessage copied_id;
    copied_id.copy(&identity);
    nzmqt::ZMQMessage copied_msg(data.at(j));
    socket->sendMessage(copied_id, nzmqt::ZMQSocket::SND_MORE);//告诉路由发给谁
    socket->sendMessage(copied_msg);//发送数据
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

bool WorkerClass::COMMObj_Analyze(const QByteArray &data, COMMObj::COMMObj &obj)
{
    if (obj.ParseFromArray(data.data(),data.size()))
    {
        return true;
    }
    qDebug() << "序列化数据失败,data = " << data;
    return false;
}
