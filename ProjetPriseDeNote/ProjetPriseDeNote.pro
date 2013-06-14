#-------------------------------------------------
#
# Project created by QtCreator 2013-05-20T17:09:11
#
#-------------------------------------------------

QT       += core gui
CONFIG += console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = ProjetPriseDeNote
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    notesmanager.cpp \
    article.cpp \
    notesexception.cpp \
    image.cpp \
    binary.cpp \
    video.cpp \
    audio.cpp \
    document.cpp \
    note.cpp \
    exportstrategy.cpp \
    notefactory.cpp \
    documentfactory.cpp \
    articlefactory.cpp \
    audiofactory.cpp \
    videofactory.cpp \
    imagefactory.cpp\
    htmlexport.cpp \
    savetextexport.cpp \
    textexport.cpp \
    latexexport.cpp \
    articlewidget.cpp \
    documentwidget.cpp \
    imagewidget.cpp \
    videowidget.cpp \
    audiowidget.cpp

HEADERS  += mainwindow.h \
    notesmanager.h \
    article.h \
    notesexception.h \
    image.h \
    binary.h \
    video.h \
    audio.h \
    document.h \
    note.h \
    exportstrategy.h \
    notefactory.h \
    documentfactory.h \
    articlefactory.h \
    audiofactory.h \
    videofactory.h \
    imagefactory.h \
    htmlexport.h \
    savetextexport.h \
    textexport.h \
    latexexport.h \
    articlewidget.h \
    documentwidget.h \
    imagewidget.h \
    videowidget.h \
    audiowidget.h

FORMS    += mainwindow.ui \
    articlewidget.ui \
    documentwidget.ui \
    imagewidget.ui \
    videowidget.ui \
    audiowidget.ui
