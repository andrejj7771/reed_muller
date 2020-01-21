TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = $$PWD/../bin

INCLUDEPATH += $$PWD/../include

HEADERS += $$PWD/../include/utils.h
HEADERS += $$PWD/../include/vector.h
HEADERS += $$PWD/../include/matrix.h
HEADERS += $$PWD/../include/reed_muller.h

SOURCES += $$PWD/../src/vector.cpp
SOURCES += $$PWD/../src/matrix.cpp
SOURCES += $$PWD/../src/reed_muller.cpp
SOURCES += $$PWD/../src/main.cpp
