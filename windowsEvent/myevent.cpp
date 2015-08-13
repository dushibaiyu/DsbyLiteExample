#include "myevent.h"

const QEvent::Type MyEvent::etype = static_cast<QEvent::Type>(QEvent::registerEventType());
