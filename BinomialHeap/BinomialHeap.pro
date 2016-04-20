#-------------------------------------------------
#
# Project created by QtCreator 2016-04-09T11:27:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BinomialHeap
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    binomialheap.cpp \
    nodo.cpp

HEADERS  += mainwindow.h \
    binomialheap.h \
    nodo.h

FORMS    += mainwindow.ui
