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


#include "global.h"


#include "glut.cpp"
#include "display.cpp"
#include "special_keys.cpp"
#include "keys.cpp"
#include "mouse.cpp"
#include "reshape.cpp"
#include "tacka.cpp"
#include "motion.cpp"
#include "timer.cpp"


int main(int argc,char ** argv)
{
    glut::init(argc,argv,window_width,window_height,"Crashing Trashing Bots");
    glutDisplayFunc(onDisplay);
    /*glut::display(prozor.show);*/
    glutKeyboardFunc(onKey);
    glutSpecialFunc(onSpecKey);
    glutReshapeFunc(onReshape);
    glutMouseFunc(onMouse);
    glutMotionFunc(onMotion);
    glutTimerFunc(TIMER,onTimer,0);
    glut::start();
    return 0;
}
