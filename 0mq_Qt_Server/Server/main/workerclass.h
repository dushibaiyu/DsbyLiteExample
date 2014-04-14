#ifndef WORKERCLASS_H
#define WORKERCLASS_H

/*
 *      数据处理类
 * 接受设备中转过来客户端发过来的数据，进行处理。
 * 不能直接生成，仅限调度类使用。
*/

//TODO:把数据库连接传到插件去
#include <QObject>
#include <QString>
#include "../../common/nzmqt.hpp"
#include "../../common/proto/COMMObj.pb.h"
//#include <mongo/client/dbclient.h>

//using namespace mongo;

class ControlWorker;

class WorkerClass : public QObject
{
    Q_OBJECT
public:
    ~WorkerClass();

    friend class ControlWorker;

signals:

public slots:
    void beginWork();//开始处理，即新建socket，然后连接到处理端。
    void exeData(); //处理数据的执行体。
    void endWork();//结束处理，即断开与处理的接口

protected:
    explicit WorkerClass(nzmqt::ZMQContext * context,QObject *parent = 0);
    inline bool COMMObj_Analyze(const QByteArray & data, COMMObj::COMMObj & obj);
private:
    nzmqt::ZMQSocket* socket;
    nzmqt::ZMQContext * context;
//    DBClientConnection * db;
};

#endif // WORKERCLASS_H
