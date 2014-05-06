#ifndef EVICTORBASE_H
#define EVICTORBASE_H

#include <Ice/Object.h>
#include <Ice/ServantLocator.h>
#include <IceUtil/IceUtil.h>
#include <map>
#include <list>
//逐出器的实现，官方例子代码
class EvictorBase : public Ice::ServantLocator
{
public:

    EvictorBase(int size);

    virtual Ice::ObjectPtr locate(const Ice::Current&, Ice::LocalObjectPtr&);
    virtual void finished(const Ice::Current&, const Ice::ObjectPtr&, const Ice::LocalObjectPtr&);
    virtual void deactivate(const std::string&);

protected:

    virtual Ice::ObjectPtr add(const Ice::Current&, Ice::LocalObjectPtr&) = 0;
    virtual void evict(const Ice::ObjectPtr&, const Ice::LocalObjectPtr&) = 0;

private:

    struct EvictorEntry;
    typedef IceUtil::Handle<EvictorEntry> EvictorEntryPtr;

    typedef std::map<Ice::Identity, EvictorEntryPtr> EvictorMap;
    typedef std::list<EvictorMap::iterator> EvictorQueue;

    struct EvictorEntry : public Ice::LocalObject
    {
        Ice::ObjectPtr servant;
        Ice::LocalObjectPtr userCookie;
        EvictorQueue::iterator queuePos;
        int useCount;
    };

    EvictorMap _map;
    EvictorQueue _queue;
    Ice::Int _size;

    IceUtil::Mutex _mutex;

    void evictServants();
};

typedef IceUtil::Handle<EvictorBase> EvictorBasePtr;

#endif
