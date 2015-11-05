TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += --std=c++11

INCLUDEPATH += ../application/src/

LIBS += -lgtest -lcucumber-cpp -lboost_regex -lboost_system

SOURCES += \
    features/step_definitions/GTestCalculatorSteps.cpp \
    ../application/src/Calculator.cpp

DISTFILES += \
    features/addition.feature \
    features/division.feature \
    features/step_definitions/cucumber.wire

HEADERS += \
    ../application/src/Calculator.h
