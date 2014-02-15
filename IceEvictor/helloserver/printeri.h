#ifndef PRINTERI_H
#define PRINTERI_H

#include "../tmp.h"

class PrinterI : public Demo::Printer
{
public:
    void printString(const ::std::string&, const ::Ice::Current&);

};
typedef IceUtil::Handle<PrinterI> PrinterIptr;

class Printer2I : public Demo::Printer2
{
public:
    void printString2(const ::std::string&, const ::Ice::Current&);
};
typedef IceUtil::Handle<Printer2I> PrinterI2ptr;

class Printer3I :public Demo::Printer3 //,Printer2I,PrinterI
{
public:
    void printString(const ::std::string&, const Ice::Current &);

    void printString2(const ::std::string&, const Ice::Current &);

    void printString3(const ::std::string&, const Ice::Current &);

    virtual void setCall(const ::Demo::callBackPrx& cb, const ::Ice::Current&);
    virtual void setInt(::Ice::Int, const ::Ice::Current&);

protected:
    ::Demo::callBackPrx cb;
};
typedef IceUtil::Handle<Printer3I> PrinterI3ptr;


#endif // PRINTERI_H
