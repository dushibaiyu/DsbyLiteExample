
QT       += core gui widgets

TARGET = ThoughtWorks
TEMPLATE = app

CONFIG += C++11


SOURCES += main.cpp\
        mainwindow.cpp \
    thoughtworksgame.cpp

HEADERS  += mainwindow.h \
    thoughtworksgame.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    README.txt
