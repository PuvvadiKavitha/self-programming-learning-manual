#-------------------------------------------------
#
# Project created by QtCreator 2016-02-01T10:16:04
#
#-------------------------------------------------

QT       -= gui

TARGET = T14Library
TEMPLATE = lib

DEFINES += T14LIBRARY_LIBRARY

SOURCES += T14Library.cpp

HEADERS += T14Library.h\
        t14library_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
