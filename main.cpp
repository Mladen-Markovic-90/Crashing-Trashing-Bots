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


#include "glut.h"
#include "display.h"
#include "special_keys.h"
#include "keys.h"
#include "mouse.h"
#include "reshape.h"


Display display;
Keys keyboard_keys;
Mouse mouse;
Reshape reshape;
Special_keys special_keys;


static void onDisplay(void)
{
    display.show();
}


static void onKey(unsigned char key, int x, int y)
{
    keyboard_keys.keys(key,x,y);
}


static void onSpecKey(int key, int x, int y)
{
    special_keys.keys(key,x,y);
}


static void onReshape(int width,int height)
{
    reshape.reshape(width,height);
}


static void onMouse(int button,int state,int x,int y)
{
    mouse.mouse(button,state,x,y);
}


int main(int argc,char ** argv)
{
    glut::init(argc,argv,500,500,(char *)"Crashing Trashing Bots");
    glutDisplayFunc(onDisplay);
    /*glut::display(prozor.show);*/
    glutKeyboardFunc(onKey);
    glutSpecialFunc(onSpecKey);
    glutReshapeFunc(onReshape);
    glutMouseFunc(onMouse);
    glut::start();
    return 0;
}
