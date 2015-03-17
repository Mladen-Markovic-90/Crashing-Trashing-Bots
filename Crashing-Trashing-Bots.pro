TEMPLATE = app


CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=c++11


LIBS += libfreeglut -lopengl32 -lglu32 -luser32


SOURCES += main.cpp \
    glut.cpp \
    special_keys.cpp \
    display.cpp \
    keys.cpp \
    reshape.cpp \
    mouse.cpp
HEADERS += glut.h \
    special_keys.h \
    keys.h \
    display.h \
    reshape.h \
    mouse.h


include(deployment.pri)
qtcAddDeployment()


