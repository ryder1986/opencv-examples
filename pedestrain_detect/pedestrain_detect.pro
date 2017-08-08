#QT += core
QT -= gui

TARGET = pedestrain_detect
CONFIG += console
CONFIG -= app_bundle
CONFIG +=c++11
TEMPLATE = app

SOURCES += main.cpp \
    pedestrian_detect.cpp

INCLUDEPATH+=./include

#LIBS +=-L/usr/lib/i386-linux-gnu/ -lopencv_core
#LIBS +=-L/usr/lib/i386-linux-gnu/ -lopencv_highgui
#LIBS +=-L/usr/lib/i386-linux-gnu/ -lopencv_objdetect
#LIBS +=-L/usr/lib/i386-linux-gnu/ -lopencv_imgproc
#LIBS +=-L/usr/lib/i386-linux-gnu/ -lopencv_ml
#LIBS +=-L/usr/lib/i386-linux-gnu/ -lopencv_video

LIBS +=-L/root/repo-github/opencv-examples/pedestrain_detect/lib -lopencv_core
LIBS +=-L/root/repo-github/opencv-examples/pedestrain_detect/lib -lopencv_highgui
LIBS +=-L/root/repo-github/opencv-examples/pedestrain_detect/lib -lopencv_ml
LIBS +=-L/root/repo-github/opencv-examples/pedestrain_detect/lib -lopencv_imgproc
LIBS +=-L/root/repo-github/opencv-examples/pedestrain_detect/lib -lopencv_video
LIBS +=-L/root/repo-github/opencv-examples/pedestrain_detect/lib -lopencv_objdetect
QMAKE_CXXFLAGS+=-std=c++11
QMAKE_LFLAGS+=-Wl,--rpath=~/repo/res/linux32/extra_libs
HEADERS += \
    pedestrian_detect.h

DISTFILES += \
    lib/cp.sh

