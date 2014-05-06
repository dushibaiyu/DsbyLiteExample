#-------------------------------------------------
#
# Project created by QtCreator 2014-04-11T13:52:57
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = LTEScanServer
CONFIG   += console
CONFIG   -= app_bundle

CONFIG += C++11

TEMPLATE = app

SOURCES +=  \
    controlworker.cpp \
    workerclass.cpp \
    switchthread.cpp \
    addonlist.cpp \
    main.cpp \
    ../../common/proto/COMMObj.pb.cc \
    configclass.cpp

HEADERS += \
    ../../common/global.hpp \
    ../../common/impl.hpp \
    ../../common/nzmqt.hpp \
    controlworker.h \
    workerclass.h \
    switchthread.h \
    datahandleinterface.h \
    addonlist.h \
    ../../common/proto/COMMObj.pb.h \
    configclass.h

win32:DESTDIR         = ../

win32:DEFINES += PROTOBUF_USE_DLLS

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/Win32.VS2010sp1/zeromq4.04/lib/ -llibzmq
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/Win32.VS2010sp1/zeromq4.04/lib/ -llibzmq_d

win32:INCLUDEPATH += $$PWD/../../lib/Win32.VS2010sp1/zeromq4.04
win32:DEPENDPATH += $$PWD/../../lib/Win32.VS2010sp1/zeromq4.04

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/Win32.VS2010sp1/GoogleProtocolBuffer2.5/release/ -llibprotobuf
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/Win32.VS2010sp1/GoogleProtocolBuffer2.5/debug/ -llibprotobuf

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/Win32.VS2010sp1/GoogleProtocolBuffer2.5/release/ -llibprotoc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/Win32.VS2010sp1/GoogleProtocolBuffer2.5/debug/ -llibprotoc

INCLUDEPATH += $$PWD/../../lib/Win32.VS2010sp1/GoogleProtocolBuffer2.5
DEPENDPATH += $$PWD/../../lib/Win32.VS2010sp1/GoogleProtocolBuffer2.5

#win32: LIBS += -LE:/Libs/mongo/ -lmongoclient

#INCLUDEPATH += E:/Libs/mongo
#DEPENDPATH += E:/Libs/mongo

#INCLUDEPATH += E:/SDK/boost_1_55_0
#DEPENDPATH += E:/SDK/boost_1_55_0
#win32:CONFIG(release, debug|release): LIBS += -LE:/SDK/boost_1_55_0/lib32-msvc/ -lboost_system-vc100-mt-gd-1_55
#else:win32:CONFIG(debug, debug|release): LIBS += -LE:/SDK/boost_1_55_0/lib32-msvc/ -lboost_system-vc100-mt-1_55
#win32:CONFIG(release, debug|release): LIBS += -LE:/SDK/boost_1_55_0/lib32-msvc/ -lboost_filesystem-vc100-mt-gd-1_55
#else:win32:CONFIG(debug, debug|release): LIBS += -LE:/SDK/boost_1_55_0/lib32-msvc/ -lboost_filesystem-vc100-mt-1_55
#win32:CONFIG(release, debug|release): LIBS += -LE:/SDK/boost_1_55_0/lib32-msvc/ -lboost_thread-vc100-mt-gd-1_55
#else:win32:CONFIG(debug, debug|release): LIBS += -LE:/SDK/boost_1_55_0/lib32-msvc/ -lboost_thread-vc100-mt-1_55

