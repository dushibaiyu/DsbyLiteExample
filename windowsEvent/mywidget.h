#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "myevent.h"

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

signals:

public slots:


protected:
    void customEvent(QEvent * e) {
        if (e->type() == MyEvent::etype) {
            qDebug() << "MyWidget::customEvent";
            e->ignore();
        } else {
            QWidget::event(e);
        }
    }
};

#endif // MYWIDGET_H
