#-------------------------------------------------
#
# Project created by QtCreator 2015-04-24T16:51:08
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = barbier
CONFIG   += console
CONFIG   -= app_bundle

QMAKE_CXXFLAGS += -std=c++0x

TEMPLATE = app


SOURCES += main.cpp \
    barber.cpp \
    customer.cpp \
    waitingroom.cpp \
    tattoocustomer.cpp \
    mowcustomer.cpp

HEADERS += \
    barber.h \
    customer.h \
    waitingroom.h \
    tattoocustomer.h \
    mowcustomer.h
