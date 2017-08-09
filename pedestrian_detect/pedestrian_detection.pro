#QT += core
QT -= gui

TARGET = pedestrain_detect
CONFIG += console
CONFIG -= app_bundle
CONFIG +=c++11
TEMPLATE = app

SOURCES += main.cpp \
    pedestrian_detect.cpp \
    h264filereader.cpp \
    h264decoder.cpp

#INCLUDEPATH+=./include
INCLUDEPATH+=./opencv249/include
#LIBS +=-L../opencv249/lib  -lopencv_core  -lopencv_highgui  -lopencv_objdetect -lopencv_imgproc -lopencv_ml -lopencv_video
#LIBS +=-L../ffmpeg253/lib  -lavcodec -lavformat -lavutil -lx264 -lswresample
#LIBS +=-L/usr/lib/i386-linux-gnu/ -lopencv_core
#LIBS +=-L/usr/lib/i386-linux-gnu/ -lopencv_highgui
#LIBS +=-L/usr/lib/i386-linux-gnu/ -lopencv_objdetect
#LIBS +=-L/usr/lib/i386-linux-gnu/ -lopencv_imgproc
#LIBS +=-L/usr/lib/i386-linux-gnu/ -lopencv_ml
#LIBS +=-L/usr/lib/i386-linux-gnu/ -lopencv_video

#LIBS +=-L/root/repo-github/opencv-examples/pedestrain_detect/lib -lopencv_core
#LIBS +=-L/root/repo-github/opencv-examples/pedestrain_detect/lib -lopencv_highgui
#LIBS +=-L/root/repo-github/opencv-examples/pedestrain_detect/lib -lopencv_ml
#LIBS +=-L/root/repo-github/opencv-examples/pedestrain_detect/lib -lopencv_imgproc
#LIBS +=-L/root/repo-github/opencv-examples/pedestrain_detect/lib -lopencv_video
#LIBS +=-L/root/repo-github/opencv-examples/pedestrain_detect/lib -lopencv_objdetect
#LIBS +=-L/root/repo/res/linux32/extra_libs/ffmpeg_2_5_3/lib -lavcodec -lavformat -lavutil -lswresample -lx264


LIBS +=   -lopencv_core  -lopencv_highgui  -lopencv_objdetect -lopencv_imgproc -lopencv_ml -lopencv_video
LIBS += -lavcodec -lavformat -lavutil -lx264 -lswresample
QMAKE_CXXFLAGS+=-std=c++11
QMAKE_LFLAGS+=-Wl,--rpath=~/repo/res/linux32/extra_libs
QMAKE_LFLAGS+=-Wl,--rpath=./lib-ffmpeg
HEADERS += \
    pedestrian_detect.h \
    h264filereader.h \
    h264decoder.h \
    common.h

DISTFILES += \
    lib/cp.sh

