#-------------------------------------------------
#
# Project created by QtCreator 2016-04-12T09:31:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ViewMarker
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    filesystem.cpp \
    appproperties.cpp \
    viewscene.cpp \
    baseview.cpp \
    markerwidget.cpp

HEADERS  += mainwindow.h \
    filesystem.h \
    appproperties.h \
    viewscene.h \
    baseview.h \
    markerwidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
