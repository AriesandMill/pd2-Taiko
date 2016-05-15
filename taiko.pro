#-------------------------------------------------
#
# Project created by QtCreator 2016-05-09T19:11:08
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp

HEADERS  += \
    form.h \
    mainwindow.h

FORMS    += mainwindow.ui \
    form.ui

RESOURCES += \
    pics.qrc \
    picture.qrc \
    music.qrc \
    drum.qrc

DISTFILES +=
