#ifndef ICESERVER_H
#define ICESERVER_H

#include <Ice/Ice.h>
#include <Ice/Service.h>
#include "myevictorbase.h"

//直接继承serivce
class server : virtual public Ice::Service
{
public:

    virtual bool start(int argc, char* argv[], int&);//启动server
//    virtual bool stop();//Server 停止

private:

    Ice::ObjectAdapterPtr _adapter;
};

bool server::start(int , char * [], int &)
{
    try
    {
        _adapter = communicator()->createObjectAdapterWithEndpoints("pritf","default -p 11111");
        _adapter->add(new /*PrintfI,communicator()->stringToIdentity("hello"));*/Printer3I,communicator()->stringToIdentity("hello"));
        _adapter->addServantLocator(new myEvictorBase(3),"");//添加逐出器/定位器
        _adapter->activate();
        communicator()->waitForShutdown();
    }
    catch(const Ice::LocalException&)
    {

        std::cout << "服务监听错误" << std::endl;
    }

    return true;
}

//bool server::stop()
//{
//    return true;
//}


#endif // ICESERVER_H
