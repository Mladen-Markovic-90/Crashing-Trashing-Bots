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


#ifndef MODEL_1
#define MODEL_1


#include "global.h"


int ugao_tocak=0;


static void tocak(float radius,float height)
{
glut::push();
    int ugao=-ugao_tocak/4;
    glut::rotate(ugao*5,0,0,1);
    ugao_tocak++;
    glut::color(0.8,0.8,0.8,1);
    glut::cylinder(radius,height);
    glut::translate(0,0,-0.1);
    glut::color(0,0,0,1);
    for(int i=0;i<4;i++)
    {
        glut::push();
            glut::rotate(i*45,0,0,1);
            glut::pravougaonik_z(5,1);
            glut::translate(0,0,height+0.2);
            glut::pravougaonik_z(5,1);
        glut::pop();
    }
glut::pop();
}


static void model_1()
{
    /* tockovi */

    glut::push();
        glut::translate(15,5,-10);
        tocak(5,2);
        glut::translate(-30,0,0);
        tocak(5,2);
        glut::translate(0,0,18);
        tocak(5,2);
        glut::translate(30,0,0);
        tocak(5,2);
    glut::pop();

    glut::push();
        glut::color(0.5,0.5,0.5,1);
        glut::translate(0,6,0);
        glut::kvadar(20,20,8);
    glut::pop();

    glut::push();
        glut::color(0.5,0.5,0,1);
        glut::translate(5,10,0);
        glut::kvadar(Tacka(-25,0,10),Tacka(15,0,10),Tacka(15,0,-10),Tacka(-25,0,-10),
                     Tacka(-15,5,5),Tacka(15,5,5),Tacka(15,5,-5),Tacka(-15,5,-5));
                /*
        glut::translate(5,10,-10);
        glut::pravougaonik(Tacka(15,0,0),Tacka(-15,0,0),Tacka(-15,5,5),Tacka(15,5,5));
        glut::translate(0,0,20);
        glut::pravougaonik(Tacka(15,0,0),Tacka(-15,0,0),Tacka(-15,5,-5),Tacka(15,5,-5));*/

    glut::pop();

    glut::push();
        glut::color(0.2,0.2,0.2,1);
        glut::translate(20,0,0);
        glut::kvadar(Tacka(0,0,10),Tacka(10,0,10),Tacka(10,0,-10),Tacka(0,0,-10),
                     Tacka(0,15,10),Tacka(0,15,10),Tacka(0,15,-10),Tacka(0,15,-10));
    glut::pop();


    glut::push();
        glut::color(0.2,0.2,0.2,1);
        glut::translate(10,17,0);
        glut::cube(4);
        glut::translate(2,0,0);
        glut::rotate(90,0,1,0);
        glut::cylinder(1,10);
    glut::pop();


}


#endif // MODEL_1

