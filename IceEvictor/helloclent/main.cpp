#include <iostream>
#include <Ice/Ice.h>
#include "../tmp.h"

using namespace std;

class callBackI : virtual public Demo::callBack
{
public:
    virtual void set(Ice::Int i, const Ice::Current &);
};

void callBackI::set(Ice::Int i, const Ice::Current &)
{
    cout << i << endl;
}

int main()
{
    cout << "Hello World!" << endl;
    try
    {

        Ice::PropertiesPtr props = Ice::createProperties();
        props->load("config.client");
        Ice::InitializationData id;
        id.properties = props;
         Ice::CommunicatorPtr m_ic = Ice::initialize(id,30402);
//        Ice::Identity id;
        Ice::ObjectPrx base
                = m_ic->stringToProxy("hello:default -h 192.168.56.101 -p 11111" );
        Demo::Printer3Prx m_prx = Demo::Printer3Prx::checkedCast(base);
        //客户端即服务端，反转实现回调
        Ice::ObjectAdapterPtr adapter = m_ic->createObjectAdapterWithEndpoints("callback","default -h localhost -p 10600");
        Demo::callBackPtr cr = new callBackI;
        adapter->add(cr, m_ic->stringToIdentity("callback"));
        adapter->activate();

        Demo::callBackPrx cb = Demo::callBackPrx::uncheckedCast(
                    adapter->createProxy(m_ic->stringToIdentity("callback")));

        m_prx->setCall(cb);
        m_prx->printString("hello word!");
        m_prx->printString2("hello word!");
        m_prx->setInt(18);
        system("pause");
        m_prx->printString3("hello word!");
//        Demo::PrintfPrx m_prx = Demo::PrintfPrx::checkedCast(base);
//        m_prx->Printf.
    }
    catch(...)
    {
        cout << "erro!" << endl;
    }
    return 0;
}

