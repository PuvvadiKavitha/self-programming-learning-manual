#-------------------------------------------------
#
# Project created by QtCreator 2016-02-01T10:24:53
#
#-------------------------------------------------

QT       -= gui

TARGET = T16StaticLib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += T16StaticLib.cpp

HEADERS += T16StaticLib.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
