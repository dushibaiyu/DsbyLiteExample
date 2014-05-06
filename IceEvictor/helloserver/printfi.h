#ifndef PRINTFI_H
#define PRINTFI_H

#include "../tmp.h"
#include "printeri.h"
#include <string>

class PrintfI : virtual public Demo::Printf
{
public:
    PrintfI();
    virtual std::string vison(const ::Ice::Current&);
};

typedef IceUtil::Handle<PrintfI> PrintfIptr;

PrintfI::PrintfI()
    :Demo::Printf(new PrinterI,new Printer2I)
{
}

std::string PrintfI::vison(const::Ice::Current &)
{
    return "1.0";
}


#endif // PRINTFI_H
