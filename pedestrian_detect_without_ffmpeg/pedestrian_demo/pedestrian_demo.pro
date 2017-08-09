QT += core
QT -= gui

TARGET = pedestrian_demo
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    pedestrian_detection.cpp

HEADERS += \
    pedestrian_detection.h

INCLUDEPATH+=./opencv249/include
LIBS +=   -lopencv_core  -lopencv_highgui  -lopencv_objdetect -lopencv_imgproc -lopencv_ml -lopencv_video
