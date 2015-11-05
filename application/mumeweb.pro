QT += core
QT -= gui

TARGET = mumeweb
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    src/Calculator.cpp

HEADERS += \
    src/Calculator.h

