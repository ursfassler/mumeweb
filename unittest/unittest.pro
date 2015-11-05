TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += --std=c++11

INCLUDEPATH += ../application/src/

LIBS += -lgtest -lgmock -lgtest_main

SOURCES += \
    ../application/src/Calculator.cpp \
    Calculator_test.cpp

HEADERS += \
    ../application/src/Calculator.h

