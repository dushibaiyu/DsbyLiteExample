#-------------------------------------------------
#
# Project created by QtCreator 2015-05-26T14:34:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CodeScan
TEMPLATE = app

CONFIG += C++11

win32:DEFINES += NO_ICONV

INCLUDEPATH += $$PWD/src

SOURCES += main.cpp\
        mainwindow.cpp \
   ImageWrapper.cpp


HEADERS  += mainwindow.h \
    ImageWrapper.h

FORMS    += mainwindow.ui

include(zxing/zxing.pri)

RC_ICONS = Barcode.ico

