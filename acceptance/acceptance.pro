TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += xml

QMAKE_CXXFLAGS += --std=c++11

INCLUDEPATH += ../application/

LIBS += -lgtest -lcucumber-cpp -lboost_regex -lboost_system

SOURCES += \
    features/step_definitions/SwitchSteps.cpp \
    ../application/MumeWeb.cpp

DISTFILES += \
    features/step_definitions/cucumber.wire \
    features/read_state_of_switch.feature

HEADERS += \
    ../application/MumeWeb.hpp \
    ../application/IMumeDbus.hpp
