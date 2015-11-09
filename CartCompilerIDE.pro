#-------------------------------------------------
#
# Project created by QtCreator 2015-11-06T20:08:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CartCompilerIDE
TEMPLATE = app


SOURCES += main.cpp\
		ide.cpp\
y.tab.c\
varint.cpp \
    Updater.cpp
HEADERS  += ide.h\
y.tab.h\
varint.h \
    Updater.h

FORMS    += ide.ui
