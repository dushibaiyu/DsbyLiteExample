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
#include <functional>
#include "../../common/proto/COMMObj.pb.h"

class DataHandleInterface
{
public:
    virtual ~DataHandleInterface(){}
    virtual QStringList getCommod() const = 0;//获取插件支持的命令
    virtual void datahandle(COMMObj::COMMObj & obj,QList<QByteArray> & data,std::function<void (const QByteArray &)> fun/*,DBClientConnection * db*/) = 0;//这个函数会被多个线程并行调用。
};

#define LTEDataInterface_iid "org.qt-project.Qt.LteDataHandle"
Q_DECLARE_INTERFACE(DataHandleInterface, LTEDataInterface_iid)

#endif // DATAHANDLEINTERFACE_H
