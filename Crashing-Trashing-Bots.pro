TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=c++11

LIBS += libfreeglut -lopengl32 -lglu32 -luser32

SOURCES += main.cpp

HEADERS += glut.h \
    special_keys.h \
    keys.h \
    display.h \
    reshape.h \
    mouse.h \
    tacka.h \
    motion.h \
    timer.h \
    global.h \
    model_1.h \
    model_2.h \
    model_3.h

include(deployment.pri)
qtcAddDeployment()

