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


#ifndef GLUT_H
#define GLUT_H


#include <GL/freeglut.h>
#include "tacka.h"


#define GL_OFF 0
#define GL_ON 1


class glut
{
public:
    static void init(int argc, char ** argv, int width, int heigth, char * name);
    static void start();    //glMainLoop
    static void begin(GLenum);  //glBegin
    static void end();  //glEnd
    /*static void display(void (*func)(void));*/
    static void color(float r,float g,float b,float a);
    static void light(int arg);
    static void lightposition(float x, float y, float z, float w);
    static void projection3D(int width, int height,int ugao,int arg1,int arg2);
    static void projection2D(int width, int height);
    static void modelview3D(float x,float y,float z);
    static void modelview2D();
    static void vertex(float x, float y, float z, float w);
    static void vertex(float x, float y, float z);
    static void vertex(Tacka t);
    static void vertex(Tacka t,float w);
    static void normal(float x, float y, float z, float w);
    static void normal(float x, float y, float z);
    static void normal(Tacka t, float w);
    static void normal(Tacka t);
    static void pravougaonik(Tacka a,Tacka b,Tacka c,Tacka d);
};


#endif // GLUT_H
