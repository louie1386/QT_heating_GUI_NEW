#-------------------------------------------------
#
# Project created by QtCreator 2016-06-06T11:22:46
#
#-------------------------------------------------

QT       += core gui
QT += serialport
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI_heating
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    lib_command.cpp \
    lib_draw.cpp \
    lib_initial.cpp \
    lib_ledprogressbar.cpp \
    lib_logfile.cpp \
    lib_serial.cpp \
    lib_timer.cpp \
    lib_display.cpp

HEADERS  += widget.h

FORMS    += widget.ui

RESOURCES += \
    icon.qrc
