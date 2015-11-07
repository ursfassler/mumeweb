# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

QT += core
QT -= gui

TARGET = fcgiTest
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += --std=c++11

LIBS += -lfcgi

INCLUDEPATH += ../application/

SOURCES += main.cpp \
    ../application/fcgi/FcgiRequest.cpp \
    RequestHandler.cpp \
    ../application/fcgi/fcgiSupport.cpp \
    ../application/http.cpp

HEADERS += \
    ../application/fcgi/FcgiRequest.hpp \
    RequestHandler.hpp \
    ../application/fcgi/fcgiSupport.hpp \
    ../application/http.hpp

