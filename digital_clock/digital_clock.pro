#-------------------------------------------------
#
# Project created by QtCreator 2023-04-15T21:02:18
#
#-------------------------------------------------

QT       += core gui
QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = digital_clock
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pommo.cpp \
    pomodoroclock.cpp \
    listwidget.cpp \
    progress.cpp \
    notepad.cpp \
    subjects.cpp \
    date.cpp \
    list.cpp

HEADERS  += mainwindow.h \
    pommo.h \
    pomodoroclock.h \
    listwidget.h \
    progress.h \
    notepad.h \
    subjects.h \
    date.h \
    list.h

FORMS    += mainwindow.ui \
    pommo.ui \
    pomodoroclock.ui \
    listwidget.ui \
    progress.ui \
    notepad.ui \
    subjects.ui \
    date.ui \
    list.ui

RESOURCES += \
    res.qrc
