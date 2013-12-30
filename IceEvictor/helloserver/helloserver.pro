TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tmp.cpp \
    EvictorBase.cpp \
    printeri.cpp

HEADERS += \
    tmp.h \
    iceServer.h \
    EvictorBase.h \
    myevictorbase.h \
    printeri.h

#添加ICE的库
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../SDK/Ice-3.5.1/lib/vc110/ -lice
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../SDK/Ice-3.5.1/lib/vc110/ -liced

INCLUDEPATH += $$PWD/../../../SDK/Ice-3.5.1/include
DEPENDPATH += $$PWD/../../../SDK/Ice-3.5.1/include


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../SDK/Ice-3.5.1/lib/vc110/ -liceutil
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../SDK/Ice-3.5.1/lib/vc110/ -liceutild

INCLUDEPATH += $$PWD/../../../SDK/Ice-3.5.1/include
DEPENDPATH += $$PWD/../../../SDK/Ice-3.5.1/include


