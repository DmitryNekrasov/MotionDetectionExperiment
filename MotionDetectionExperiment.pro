#-------------------------------------------------
#
# Project created by QtCreator 2015-06-09T18:07:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MotionDetectionExperiment
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    core.cpp

HEADERS  += mainwindow.h \
    core.h

FORMS    += mainwindow.ui

LIBS += -L/opt/local/lib \
        -lopencv_highgui \
        -lopencv_core \
        -lopencv_video \
        -lopencv_imgproc \
        -lopencv_nonfree

LIBS += -lopencv_ml
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann

INCLUDEPATH += /opt/local/include
