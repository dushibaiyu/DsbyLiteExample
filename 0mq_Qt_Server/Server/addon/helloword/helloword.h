#ifndef HELLOWORD_H
#define HELLOWORD_H
#include <QObject>
#include <QtPlugin>
#include <datahandleinterface.h>

class  Helloword  : public QObject,DataHandleInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID LTEDataInterface_iid)
    Q_INTERFACES(DataHandleInterface)
public:
    Helloword();
    bool datahandle(const QByteArray & data, QList<QByteArray> &);
};

#endif // HELLOWORD_H
