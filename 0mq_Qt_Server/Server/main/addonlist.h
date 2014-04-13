#ifndef ADDONLIST_H
#define ADDONLIST_H

#include "datahandleinterface.h"
#include <QMultiMap>

class AddonList
{
public:
    ~AddonList(){}
    static AddonList & getClass();

    QList<DataHandleInterface *> getInterface(const QString & key) const;
    int getsize() const;

protected:
    void loadAddon();

private:
    AddonList();
    QMultiMap<QString,DataHandleInterface* > addonMap;
};

#endif // ADDONLIST_H
