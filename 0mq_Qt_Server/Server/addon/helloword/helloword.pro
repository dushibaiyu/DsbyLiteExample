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

win32:DESTDIR         = ../../plugins

EXAMPLE_FILES = helloplugin.json



