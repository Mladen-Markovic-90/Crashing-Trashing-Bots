TEMPLATE = app


CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=c++11


LIBS += libfreeglut -lopengl32 -lglu32 -luser32


SOURCES += main.cpp


HEADERS += glutcpp/glutcpp.h \
    display.h \
    glutcpp/tacka.h \
    global.h \
    robot.h \
    robot_1.h \
    robot_2.h \
    robot_3.h \
    delovi.h \
    vektor3d.h \
    glutcpp/glutDisplay.h \
    glutcpp/glutNormalKeyListener.h \
    normalKeyListener.h \
    glutcpp/glutMotionListener.h \
    motionListener.h \
    mouseListener.h \
    glutcpp/glutMouseListener.h \
    glutcpp/glutReshapeListener.h \
    reshapeListener.h \
    glutcpp/glutAnimationTimer.h \
    animationTimer.h \
    specialKeyListener.h \
    glutcpp/glutSpecialKeyListener.h \
    provera.h \
    animationStatus.h \
    glutcpp/glutLoadPicture.h \
    telo.h \
    prepreka.h \
    abilitys/robot1_ability1.h \
    abilitys/robot1_ability2.h \
    abilitys/robot2_ability1.h \
    abilitys/robot2_ability2.h \
    abilitys/ability.h \
    abilitys/robot3_ability1.h \
    abilitys/robot3_ability2.h

include(deployment.pri)
qtcAddDeployment()
