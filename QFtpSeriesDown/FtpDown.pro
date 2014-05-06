#-------------------------------------------------
#
# Project created by QtCreator 2013-11-19T09:09:39
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FtpDown
TEMPLATE = app

CONFIG += C++11

SOURCES += main.cpp\
        mainwindow.cpp \
    ftpcutdown.cpp \
    qurlinfo.cpp \
    qftp.cpp

HEADERS  += mainwindow.h \
    ftpcutdown.h \
    qurlinfo.h \
    qftp.h

FORMS    += mainwindow.ui
