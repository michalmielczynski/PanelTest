#-------------------------------------------------
#
# Project created by QtCreator 2011-03-14T10:01:19
#
#-------------------------------------------------

QT       += core gui
QT += opengl

TARGET = PanelTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagepropertiesdockwidget.cpp \
    imageeffectsdockwidget.cpp \
    qgraphicsbloomfilter.cpp \
    qgraphicsnoisereductionfilter.cpp \
    qgraphicsblurfilter.cpp \
    qgraphicsvingettingfilter.cpp \
    qgraphicssharpenfilter.cpp \
    qgraphicschromaticaberrationfilter.cpp \
    mythread.cpp

HEADERS  += mainwindow.h \
    imagepropertiesdockwidget.h \
    imageeffectsdockwidget.h \
    qgraphicsbloomfilter.h \
    qgraphicsnoisereductionfilter.h \
    qgraphicsblurfilter.h \
    qgraphicsvingettingfilter.h \
    qgraphicssharpenfilter.h \
    qgraphicschromaticaberrationfilter.h \
    mythread.h

FORMS    += mainwindow.ui \
    imagepropertiesdockwidget.ui \
    imageeffectsdockwidget.ui
