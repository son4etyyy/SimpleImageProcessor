#-------------------------------------------------
#
# Project created by QtCreator 2015-12-26T11:33:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleImageProcessor
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        graylevelhistogram.cpp\
        blur.cpp \
        sharpen.cpp \
        grayscale.cpp \
    leveldialog.cpp

HEADERS  += mainwindow.h \
    graylevelhistogram.h \
    imagefilter.h \
    grayscale.h \
    blur.h \
    sharpen.h \
    leveldialog.h

FORMS    += mainwindow.ui \
            leveldialog.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/qwt-6.1.2/lib/release/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/qwt-6.1.2/lib/debug/ -lqwt
else:unix: LIBS += -L$$PWD/qwt-6.1.2/lib/ -lqwt

INCLUDEPATH += $$PWD/qwt-6.1.2/include
DEPENDPATH += $$PWD/qwt-6.1.2/include

DISTFILES +=
