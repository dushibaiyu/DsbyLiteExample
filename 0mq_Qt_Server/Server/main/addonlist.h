#ifndef ADDONLIST_H
#define ADDONLIST_H

#include "datahandleinterface.h"
#include <QList>

class AddonList
{
public:
    ~AddonList(){}
    static AddonList & getClass();

    DataHandleInterface * const & at(int i) const;
    int getsize() const;

protected:
    void loadAddon();

private:
    AddonList();
    QList<DataHandleInterface* > list;
    int size;
};

#endif // ADDONLIST_H
