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
    QStringList getCommod() const;
    void  datahandle(COMMObj::COMMObj & obj, QList<QByteArray> & data,std::function<void (const QByteArray &)> fun);
};

#endif // HELLOWORD_H
