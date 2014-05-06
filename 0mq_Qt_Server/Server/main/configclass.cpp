#include "configclass.h"
#include <QSettings>

ConfigClass::ConfigClass()
{
    loadConf();
    saveConf();
}

void ConfigClass::saveConf()
{
    QSettings conf("LTEServer.conf",QSettings::IniFormat);
    conf.setValue("Server/route",isBind);
    conf.setValue("Server/ClientBind",outBind);
    conf.setValue("Server/serverBind",inBind);
    conf.setValue("HandleData/Address",conAddress);
    conf.setValue("DataBase/Address",mongoAddress);
}

void ConfigClass::loadConf()
{
    QSettings conf("LTEServer.conf",QSettings::IniFormat);
    isBind = conf.value("Server/route",true).toBool();
    outBind = conf.value("Server/ClientBind","tcp://*:6666").toString();
    inBind = conf.value("Server/serverBind","tcp://*:6668").toString();
    conAddress = conf.value("HandleData/Address","tcp://127.0.0.1:6668").toString();
    mongoAddress = conf.value("DataBase/Address","127.0.0.1:27017").toString();
}

const ConfigClass & ConfigClass::getClass()
{
    static ConfigClass conf;
    return conf;
}
