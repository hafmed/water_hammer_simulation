#-------------------------------------------------
# HAF 5-1-2018 , 23-7-2020
# on Qt 5.9.5 GCC 7.3.0; 64 bit Qt Creator 4.5.2 Ubuntu 18.4
# sudo apt install g++
# sudo apt install cmake
# sudo apt-get install libgl-dev
# sudo apt-get install qt5-default
#------------Make *.AppImage----------------------
# in the directorie : compilation
# chmod a+x linuxdeployqt-6-x86_64.AppImage
# ./linuxdeployqt-6-x86_64.AppImage water-hammer-simulation -appimage -qmake=/home/hafmed/Qt5.12.8/5.12.8/gcc_64/bin/qmake
#-------------------------------------------------

QT       += core gui
CONFIG += c++17
VERSION = 1.9.0 # HAF 1-9-2020
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

QMAKE_CXXFLAGS += -std=c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = water-hammer-simulation
TEMPLATE = app

SOURCES += main.cpp\
        water-hammer-simulation.cpp \
    qcustomplot/qcustomplot.cpp

HEADERS  += water-hammer-simulation.h \
    qcustomplot/qcustomplot.h

FORMS    += water-hammer-simulation.ui

RESOURCES += \
    qtresource.qrc

win32:RC_ICONS += icons\water-hammer-simulation.ico

