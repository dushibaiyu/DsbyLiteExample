#ifndef MYEVICTORBASE_H
#define MYEVICTORBASE_H

#include "EvictorBase.h"
#include "printfi.h"
//实现逐出器的功能
class myEvictorBase : virtual public EvictorBase//逐出器
{
public:
    myEvictorBase(int size = 500);

protected:
    virtual Ice::ObjectPtr add(const Ice::Current&, Ice::LocalObjectPtr&);
    virtual void evict(const Ice::ObjectPtr&, const Ice::LocalObjectPtr&);

};

typedef IceUtil::Handle<myEvictorBase> myEvictorBaseptr;

myEvictorBase::myEvictorBase(int size)
    :EvictorBase(size)
{
}

Ice::ObjectPtr myEvictorBase::add(const Ice::Current& id , Ice::LocalObjectPtr&)//找不到事的添加动作
{
    //格式：category/name
    std::cout << "facet : " << id.facet << "  IDname : " << id.id.name << " IDcategory : " << id.id.category << std::endl;
    return  new Printer3I;
}

void myEvictorBase::evict(const Ice::ObjectPtr&, const Ice::LocalObjectPtr&)
{}

//测试定位器
//class MyLocator : virtual public Ice::ServantLocator //定位器
//{
//public:
//    virtual Ice::ObjectPtr locate(const Ice::Current& ,
//        Ice::LocalObjectPtr& )
//    {
//       return new Printer3I;
//    }

//    virtual void finished(const Ice::Current& ,
//        const Ice::ObjectPtr& , const Ice::LocalObjectPtr&)
//    {
//    }

//    virtual void deactivate(const std::string& )
//    {
//    }
//};
#endif // MYEVICTORBASE_H
