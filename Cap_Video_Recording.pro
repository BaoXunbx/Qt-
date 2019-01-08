#-------------------------------------------------
#
# Project created by QtCreator 2019-01-08T16:04:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cap_Video_Recording
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH+=D:\opencv2413\opencv\build\include\
D:\opencv2413\opencv\build\include\opencv\
D:\opencv2413\opencv\build\include\opencv2
LIBS +=-LD:\opencv2413\opencv\build\x86\vc11\lib \
-lopencv_ml2413d\
-lopencv_calib3d2413d\
-lopencv_contrib2413d\
-lopencv_core2413d\
-lopencv_features2d2413d\
-lopencv_flann2413d\
-lopencv_gpu2413d\
-lopencv_highgui2413d\
-lopencv_imgproc2413d\
-lopencv_legacy2413d\
-lopencv_objdetect2413d\
-lopencv_ts2413d\
-lopencv_video2413d\
-lopencv_nonfree2413d\
-lopencv_ocl2413d\
-lopencv_photo2413d\
-lopencv_stitching2413d\
-lopencv_superres2413d\
-lopencv_videostab2413d
