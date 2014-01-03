#include <iostream>
#include <Ice/Ice.h>
#include "../helloserver/tmp.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    try
    {
        Ice::CommunicatorPtr m_ic = Ice::initialize();
        Ice::Identity id;
        Ice::ObjectPrx base
                = m_ic->stringToProxy("hello/php:default -h localhost -p 11111" );
        Demo::Printer3Prx m_prx = Demo::Printer3Prx::checkedCast(base);//::checkedCast(base);
        m_prx->printString("hello word!");
        m_prx->printString2("hello word!");
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

