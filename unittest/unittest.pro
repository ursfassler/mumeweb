TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += xml

QMAKE_CXXFLAGS += --std=c++11

INCLUDEPATH += ../application/

LIBS += -lgtest -lgmock -lgtest_main

SOURCES += \
    MumeWeb_test.cpp \
    ../application/MumeWeb.cpp \
    fcgi/fcgiSupport_test.cpp \
    ../application/fcgi/fcgiSupport.cpp

HEADERS += \
    ../application/MumeWeb.hpp \
    ../application/IMumeDbus.hpp \
    mocks/MumeDbus_Mock.hpp \
    ../application/fcgi/fcgiSupport.hpp

