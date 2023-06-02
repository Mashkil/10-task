#-------------------------------------------------
#
# Project created by QtCreator 2023-01-14T23:28:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dima_10
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    select_type.cpp \
    select_time.cpp \
    output_info.cpp \
    selectdataandtimeforexpress.cpp \
    chooseseat.cpp \
    printticket.cpp

HEADERS += \
        mainwindow.h \
    select_type.h \
    select_time.h \
    output_info.h \
    selectdataandtimeforexpress.h \
    chooseseat.h \
    printticket.h

FORMS += \
        mainwindow.ui \
    select_type.ui \
    select_time.ui \
    output_info.ui \
    selectdataandtimeforexpress.ui \
    chooseseat.ui \
    printticket.ui
