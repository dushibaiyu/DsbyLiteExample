#-------------------------------------------------
#
# Project created by QtCreator 2014-04-11T15:43:12
#
#-------------------------------------------------
QT       += core

QT       -= gui

TEMPLATE = lib
CONFIG += C++11
DEFINES += HELLOWORD_LIBRARY

INCLUDEPATH += $$PWD/../../main

SOURCES += helloword.cpp

HEADERS += helloword.h

TARGET          = $$qtLibraryTarget(hello)

win32:DEFINES += PROTOBUF_USE_DLL
win32:DESTDIR         = ../../plugins

EXAMPLE_FILES = helloplugin.json

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../lib/Win32.VS2010sp1/GoogleProtocolBuffer2.5/release/ -llibprotoc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../lib/Win32.VS2010sp1/GoogleProtocolBuffer2.5/debug/ -llibprotoc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../lib/Win32.VS2010sp1/GoogleProtocolBuffer2.5/release/ -llibprotobuf
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../lib/Win32.VS2010sp1/GoogleProtocolBuffer2.5/debug/ -llibprotobuf

INCLUDEPATH += $$PWD/../../../lib/Win32.VS2010sp1/GoogleProtocolBuffer2.5
DEPENDPATH += $$PWD/../../../lib/Win32.VS2010sp1/GoogleProtocolBuffer2.5
