#-------------------------------------------------
#
# Project created by QtCreator 2015-08-13T15:33:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = windowsEvent
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myobject.cpp \
    mywidget.cpp \
    myevent.cpp

HEADERS  += mainwindow.h \
    myobject.h \
    mywidget.h \
    myevent.h

FORMS    += mainwindow.ui
