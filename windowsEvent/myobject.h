#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include "myevent.h"

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = 0);

signals:

public slots:

protected:
    void customEvent(QEvent * e) {
        if (e->type() == MyEvent::etype) {
            qDebug() << "MyObject::customEvent";
            e->ignore();
        } else {
            QObject::event(e);
        }
    }
};

#endif // MYOBJECT_H
