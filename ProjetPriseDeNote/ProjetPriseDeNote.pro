#-------------------------------------------------
#
# Project created by QtCreator 2013-05-20T17:09:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetPriseDeNote
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Notes.cpp \
    exportstrategy.cpp

HEADERS  += mainwindow.h \
    notes.h \
    exportstrategy.h

FORMS    += mainwindow.ui
