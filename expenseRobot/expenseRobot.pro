#-------------------------------------------------
#
# Project created by QtCreator 2018-04-02T15:10:13
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets network script sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = expenseRobot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    welcome.cpp \
    voicecheck.cpp \
    qaudiolevel.cpp

HEADERS  += mainwindow.h \
    welcome.h \
    voicecheck.h \
    qaudiolevel.h

FORMS += \
    mainwindow.ui

DISTFILES +=
