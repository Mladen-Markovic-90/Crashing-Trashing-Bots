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


/* klasa koja je globalna i ukljucuje sve includes */


#ifndef GLOBAL_H
#define GLOBAL_H


#include "glut.h"
#include "display.h"
#include "keys.h"
#include "motion.h"
#include "mouse.h"
#include "reshape.h"
#include "special_keys.h"
#include "tacka.h"
#include "timer.h"
#include "model_1.h"
#include "model_2.h"
#include "model_3.h"
#include "robot.h"
#include <vector>


/* definicije za trenutni prozor */
#define MODUS_MENI 0
#define MODUS_START 1
#define MODUS_ARENA 2
#define MODUS_3 3
#define MODUS_4 4
#define MODUS_5 5
#define MODUS_6 6
#define MODUS_TEST 7


#define PII 3.14159265359


int modus=MODUS_START; /* trenutni prozor */

/* sirina i visina */
int window_width=500;
int window_height=500;


/* specijalne globalne promenljive */
Keys keyboard_keys;
Mouse mouse;
Reshape reshape;
Special_keys special_keys;
Motion motion;
Display display;
Timer timer;
std::vector<Robot *> robot;


/* sledi nekoliko funkcija za ulaz u glutXXXXfunc() */


static void onTimer(int id)
{
    timer.timer(id);
}


static void onDisplay(void)
{
    display.show();
}


static void setKey(unsigned char key, int x, int y)
{
    keyboard_keys.setKey(key,x,y);
}


static void setSpecKey(int key, int x, int y)
{
    //glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    //glutIgnoreKeyRepeat(1);
    special_keys.setKey(key,x,y);
}


static void onReshape(int width,int height)
{
    reshape.reshape(width,height);
}


static void onMouse(int button,int state,int x,int y)
{
    mouse.mouse(button,state,x,y);
}


static void onMotion(int x,int y)
{
    motion.motion(x,y);
}


static void unsetKey(unsigned char key, int x, int y)
{
    //glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    //glutIgnoreKeyRepeat(1);
    keyboard_keys.unsetKey(key,x,y);
}


static void unsetSpecKey(int key, int x, int y)
{
    //glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    //glutIgnoreKeyRepeat(1);
    special_keys.unsetKey(key,x,y);
}


#endif // GLOBAL_H
