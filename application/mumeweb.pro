QT += core
QT -= gui

TARGET = mumeweb
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    MumeWeb.cpp

HEADERS += \
    MumeWeb.hpp \
    IMumeDbus.hpp

