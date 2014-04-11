#ifndef DATAHANDLEINTERFACE_H
#define DATAHANDLEINTERFACE_H

#include <QObject>
#include <list>
#include <QByteArray>

class DataHandleInterface
{
public:
    virtual ~DataHandleInterface(){}
    virtual bool datahandle(const QByteArray & data,QList<QByteArray> &) = 0;
};

#define LTEDataInterface_iid "org.qt-project.Qt.LteDataHandle"
Q_DECLARE_INTERFACE(DataHandleInterface, LTEDataInterface_iid)

#endif // DATAHANDLEINTERFACE_H
