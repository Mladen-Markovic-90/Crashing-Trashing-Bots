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


#ifndef DELOVI_H
#define DELOVI_H


#include "global.h"


class Delovi
{
public:

    static void tocak(float radius,float height,int ugao)
    {
    glut::push();
        glut::rotate(-ugao*5,0,0,1);
        glut::color(0.8,0.8,0.8,1);
        glut::cylinder(radius,height);
        glut::translate(0,0,-0.1);
        glut::color(0,0,0,1);
        for(int i=0;i<4;i++)
        {
            glut::push();
                glut::rotate(i*45,0,0,1);
                glut::pravougaonik_z(radius,height/2);
                glut::translate(0,0,height+0.2);
                glut::pravougaonik_z(radius,height/2);
            glut::pop();
        }
    glut::pop();
    }

};


#endif // DELOVI_H
