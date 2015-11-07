# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

TEMPLATE = app
TARGET = mumeweb
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

QT += xml
QT += core
QT += dbus
QT -= gui

QMAKE_CXXFLAGS += --std=c++11

LIBS += -lfcgi

dbusProxy.target = dbusProxy
dbusProxy.commands = qdbusxml2cpp $$PWD/mumesrv.xml -p $$PWD/generated/MumeSrvProxy
QMAKE_EXTRA_TARGETS += dbusProxy
PRE_TARGETDEPS += dbusProxy

SOURCES += main.cpp \
    MumeWeb.cpp \
    generated/MumeSrvProxy.cpp \
    fcgi/FcgiRequest.cpp \
    fcgi/fcgiSupport.cpp \
    http.cpp

HEADERS += \
    MumeWeb.hpp \
    IMumeDbus.hpp \
    generated/MumeSrvProxy.h \
    fcgi/FcgiRequest.hpp \
    fcgi/fcgiSupport.hpp \
    http.hpp

DISTFILES += \
    mumesrv.xml

