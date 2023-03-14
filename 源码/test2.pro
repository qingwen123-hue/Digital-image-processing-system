QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FFT.cpp \
    brightnesscontrast.cpp \
    cameratthread.cpp \
    edgedetection.cpp \
    equalization.cpp \
    frequencydomain.cpp \
    gaussianfiltering.cpp \
    generalfunction.cpp \
    generalinterface.cpp \
    grayscale.cpp \
    linearblending.cpp \
    main.cpp \
    mainwindow.cpp \
    morphology.cpp \
    resize.cpp

HEADERS += \
    FFT.h \
    brightnesscontrast.h \
    cameratthread.h \
    edgedetection.h \
    equalization.h \
    frequencydomain.h \
    gaussianfiltering.h \
    generalfunction.h \
    generalinterface.h \
    grayscale.h \
    linearblending.h \
    mainwindow.h \
    morphology.h \
    resize.h

FORMS += \
    brightnesscontrast.ui \
    edgedetection.ui \
    equalization.ui \
    frequencydomain.ui \
    gaussianfiltering.ui \
    generalinterface.ui \
    grayscale.ui \
    linearblending.ui \
    mainwindow.ui \
    morphology.ui \
    resize.ui

INCLUDEPATH += D:\opencv\OpenCV-MinGW-Build-OpenCV-4.0.1-x64\include

LIBS += D:\opencv\OpenCV-MinGW-Build-OpenCV-4.0.1-x64\x64\mingw\bin\libopencv_*.dll

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


