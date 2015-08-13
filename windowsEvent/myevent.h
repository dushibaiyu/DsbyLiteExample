#ifndef MYEVENT
#define MYEVENT

#include <QEvent>
#include <QDebug>

class MyEvent : public QEvent
{
public :
    explicit MyEvent():QEvent(etype){}

    const static Type etype;
};

#endif // MYEVENT

