#include "printeri.h"

void PrinterI::printString(const ::std::string& str, const ::Ice::Current&)
{
    std::cout << str << "  :1" << std::endl;
}

void Printer2I::printString2(const::std::string & str, const Ice::Current &)
{
    std::cout  << str <<"  :2" << std::endl;
}

void Printer3I::printString3(const ::std::string& str, const ::Ice::Current&)
{
    std::cout << str << "  :3" << std::endl;
}

void Printer3I::printString(const ::std::string& str, const ::Ice::Current&)
{
    std::cout << str << "  :13" << std::endl;
}

void Printer3I::printString2(const::std::string & str, const Ice::Current &)
{
    std::cout  << str <<"  :23" << std::endl;
}
