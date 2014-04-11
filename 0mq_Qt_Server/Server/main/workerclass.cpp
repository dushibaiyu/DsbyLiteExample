#include "workerclass.h"
#include <QThread>
#include "addonlist.h"

WorkerClass::WorkerClass(nzmqt::ZMQContext *context, const QString & str, QObject *parent) :
    QObject(parent),address(str),
    context(context),socket(nullptr)
{
}

WorkerClass::~WorkerClass()
{
    if (socket != nullptr)
    {
        delete socket;
    }
}

void WorkerClass::beginWork()
{
    socket = context->createSocket(nzmqt::ZMQSocket::TYP_DEALER,this);
    connect(socket,&nzmqt::ZMQSocket::readyRead,this,&WorkerClass::exeData);
    socket->connectTo(address);
}

void WorkerClass::exeData()
{
    nzmqt::ZMQMessage identity;
    nzmqt::ZMQMessage msg;
    nzmqt::ZMQMessage copied_id;
    bool ok = socket->receiveMessage(&identity);
    if (ok && socket->receiveMessage(&msg))
    {
        QList<QByteArray> data;
        for (int i = 0; i < AddonList::getClass().getsize(); ++i)
        {
            if (AddonList::getClass().at(i)->datahandle(msg.toByteArray(),data))
            {
                break;
            }
        }

        for (int i = 0; i < data.size(); ++i)
        {
            copied_id.copy(&identity);
            nzmqt::ZMQMessage copied_msg(data.at(i));
            socket->sendMessage(copied_id, nzmqt::ZMQSocket::SND_MORE);
            socket->sendMessage(copied_msg);
        }
        data.clear();
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
