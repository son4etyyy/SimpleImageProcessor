#-------------------------------------------------
#
# Project created by QtCreator 2015-12-26T11:33:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = SimpleImageProcessor
TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    graylevelhistogram.cpp\
    grayscale.cpp \
    qcustomplot.cpp \
    otsu.cpp \
    displaywindow.cpp \
    lineselect.cpp

HEADERS  += mainwindow.h \
    graylevelhistogram.h \
    imagefilter.h \
    grayscale.h \
    qcustomplot.h \
    otsu.h \
    displaywindow.h \
    lineselect.h

FORMS    += mainwindow.ui \
    displaywindow.ui \
    lineselect.ui

DISTFILES +=
