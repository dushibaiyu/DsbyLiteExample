#ifndef CONFIGCLASS_H
#define CONFIGCLASS_H

#include <QString>

class ConfigClass
{
public:
    static const ConfigClass & getClass();

    QString outBind;
    QString inBind;
    bool isBind;
    QString conAddress;
    QString mongoAddress;

protected:
    void loadConf();
    void saveConf();
private:
   explicit ConfigClass();
};

#endif // CONFIGCLASS_H
