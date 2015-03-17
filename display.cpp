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


#include "display.h"
#include "glut.h"
#include "tacka.h"
#include <iostream>


Display display;


void Display::show(void)
{
    if(modus==MODUS_MENI)
        Display::meni();
    else if(modus==MODUS_START)
        Display::start();
}


void Display::meni()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glut::color(1,0,0,1);
    Tacka t(1,2,3);
    std::cout << t.get_x() << t.get_y() << t.get_z() << std::endl;
    glut::begin(GL_QUADS);
        glVertex3f(0.5,0.5,0);
        glVertex3f(-0.5,0.5,0);
        glVertex3f(-0.5,-0.5,0);
        glVertex3f(0.5,-0.5,0);
    glut::end();
    //Display::modus++; TEST
    glutSwapBuffers();
}

// TEST
void Display::start()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glut::color(0,0,0,1);
    glut::begin(GL_QUADS);
        glVertex3f(0.5,0.5,0);
        glVertex3f(-0.5,0.5,0);
        glVertex3f(-0.5,-0.5,0);
        glVertex3f(0.5,-0.5,0);
    glut::end();
    glutSwapBuffers();
}
