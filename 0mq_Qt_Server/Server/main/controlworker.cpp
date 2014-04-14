#include "controlworker.h"
#include <QThread>

ControlWorker::ControlWorker(QObject *parent) :
    QObject(parent),istarted(false)
{
    context = nzmqt::createDefaultContext(this,2);
}

ControlWorker::~ControlWorker()
{
    endAllWork();
    for (int i = 0; i < wklist.size(); ++i)
    {
        WorkerClass * wk = wklist.at(i);
        wk->thread()->exit();
        wk->thread()->wait();
        wk->~WorkerClass();
    }
    delete context;
}

void ControlWorker::beginWork(int interval,long timeout)
{
    if (!istarted)
    {
        if(wklist.isEmpty())
            return;
        istarted = true;
        context->setInterval(interval);
        context->setPollTimeOut(timeout);
        context->start();
        emit startWorker();
    }
}

void ControlWorker::endAllWork()
{
    if (istarted)
    {
        istarted = false;
        context->stop();
        emit endWorker();
    }
}

void ControlWorker::setWork(int size)
{
    if (size <= 0)
    {
        size = 1;
    }
    if (!istarted)
    {
        for (int i =0 ; i< size ; ++i)
        {
            WorkerClass * wk = new WorkerClass(context);
            connect(this,&ControlWorker::startWorker,wk,&WorkerClass::beginWork);
            connect(this,&ControlWorker::endWorker,wk,&WorkerClass::endWork);
            QThread * th = new QThread(wk);
            wk->moveToThread(th);
            th->start();
            wklist.append(wk);
        }
    }
}
