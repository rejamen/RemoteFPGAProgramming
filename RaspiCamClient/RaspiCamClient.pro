#-------------------------------------------------
#
# Project created by QtCreator 2017-06-01T14:56:44
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RaspiCamClient
TEMPLATE = app


SOURCES += main.cpp\
        raspcammw.cpp \
    controlclient.cpp \
    dlgrecord.cpp \
    netscaner.cpp \
    tcprequest.cpp \
    videoview.cpp

HEADERS  += raspcammw.h \
    controlclient.h \
    dlgrecord.h \
    netscaner.h \
    tcprequest.h \
    videoview.h

FORMS    += raspcammw.ui \
    dlgrecord.ui

unix:LIBS += -lvlc

RESOURCES += \
    icons.qrc
