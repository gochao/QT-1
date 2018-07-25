#-------------------------------------------------
#
# Project created by QtCreator 2018-07-25T10:08:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_single_slot
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    subwidget.cpp

HEADERS  += widget.h \
    subwidget.h

CONFIG += C++11
