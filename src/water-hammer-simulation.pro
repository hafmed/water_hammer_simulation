#-------------------------------------------------
# HAF 5-1-2018 , 9-9-2020
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
VERSION = 4.3.1 # HAF 1-5-2021 ; 25-7-2021; 9-8-2021; 15-5-2022; 9-7-2022; 29-7-2022
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

QMAKE_CXXFLAGS += -std=c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

android:DISTFILES += \
android-sources/AndroidManifest.xml \
android-sources/build.gradle

ANDROID_VERSION_CODE = 032431

android:ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources

TARGET = water-hammer-simulation
TEMPLATE = app

SOURCES += main.cpp\
            water-hammer-simulation.cpp \
            qcustomplot/qcustomplot.cpp

HEADERS  += water-hammer-simulation.h \
            constants \
            qcustomplot/qcustomplot.h

FORMS    += water-hammer-simulation.ui

TRANSLATIONS = translations/qt_en.ts

RESOURCES += \
    qtresource.qrc \
    translations.qrc

win32:RC_ICONS += icons\water-hammer-simulation.ico

DISTFILES += \
    android-sources/AndroidManifest.xml \
    android-sources/build.gradle \
    android-sources/res/drawable-hdpi/icon.png \
    android-sources/res/drawable-ldpi/icon.png \
    android-sources/res/drawable-mdpi/icon.png \
    android-sources/res/drawable-xhdpi/icon.png \
    android-sources/res/drawable-xxhdpi/icon.png \
    android-sources/res/drawable-xxxhdpi/icon.png

