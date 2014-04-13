#ifndef WORKERCLASS_H
#define WORKERCLASS_H

/*
 *      数据处理类
 * 接受设备中转过来客户端发过来的数据，进行处理。
 * 不能直接生成，仅限调度类使用。
*/


#include <QObject>
#include <QString>
#include "../../common/nzmqt.hpp"
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
    explicit WorkerClass(nzmqt::ZMQContext * context, const QString & address,
                         /*const QString & dbadd,*/ QObject *parent = 0);

private:
    QString address;//连接地址
    QString dbAddress;//数据库连接地址
    nzmqt::ZMQSocket* socket;
    nzmqt::ZMQContext * context;
//    DBClientConnection * db;
};

#endif // WORKERCLASS_H
