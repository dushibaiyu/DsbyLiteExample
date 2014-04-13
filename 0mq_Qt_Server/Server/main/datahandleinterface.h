#ifndef DATAHANDLEINTERFACE_H
#define DATAHANDLEINTERFACE_H
/*
 * 插件接口类
 *继承此接口进行开发服务器处理数据的插件。
*/

#include <QObject>
#include <list>
#include <QByteArray>
#include <QStringList>

class DataHandleInterface
{
public:
    virtual ~DataHandleInterface(){}
    virtual QStringList getCommod() const = 0;
    virtual void datahandle(const QByteArray & data,QList<QByteArray> &) = 0;
};

#define LTEDataInterface_iid "org.qt-project.Qt.LteDataHandle"
Q_DECLARE_INTERFACE(DataHandleInterface, LTEDataInterface_iid)

#endif // DATAHANDLEINTERFACE_H
