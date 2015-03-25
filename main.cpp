/*
    Crashing Trashing Bots is a 3D game in freeglut
    Copyright (C) 2015 Mladen Markovic,Tamara Plazinic,Nikola Banjac

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/* Ukljucujemo sve headere i globalne promenljive */
#include "global.h"


/* Ukljucujemo sve .cpp fajlove za olaksavanje pravljenje makefile */
#include "glut.cpp"
#include "display.cpp"
#include "special_keys.cpp"
#include "keys.cpp"
#include "mouse.cpp"
#include "reshape.cpp"
#include "tacka.cpp"
#include "motion.cpp"
#include "timer.cpp"
#include "robot.cpp"
#include "robot_1.cpp"
#include "robot_2.cpp"
#include "robot_3.cpp"


int main(int argc,char ** argv)
{
    if(modus==MODUS_TEST_MLADEN)
    {
        roboti.push_back(new Robot_1);
        roboti.push_back(new Robot_3(PLAYER_TEST));
        roboti.push_back(new Robot_2(PLAYER_2));
        roboti.push_back(new Robot_1(PLAYER_1));
    }
    else
    {
        roboti.push_back(new Robot_1);
        // roboti.push_back(new Robot_3(PLAYER_1));
        // roboti.push_back(new Robot_2(PLAYER_2));
        roboti.push_back(new Robot_1(PLAYER_1));
    }

    /* Inicalizujemo glut */
    glut::init(argc,argv,window_width,window_height,"Crashing Trashing Bots");

    //glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    //glutIgnoreKeyRepeat(1);
    //glutEnterGameMode();
    //glutFullScreen();
    /*glut::display(prozor.show);*/

    /* Ukljucujemo glut funkcije */
    glutDisplayFunc(onDisplay);
    glutKeyboardFunc(setKey);
    glutKeyboardUpFunc(unsetKey);
    glutSpecialFunc(setSpecKey);
    glutSpecialUpFunc(unsetSpecKey);
    glutReshapeFunc(onReshape);
    glutMouseFunc(onMouse);
    glutMotionFunc(onMotion);
    glutTimerFunc(TIMER,onTimer,0);

    /* Pokrecemo glut petlju */
    glut::start();

    return 0;
}
