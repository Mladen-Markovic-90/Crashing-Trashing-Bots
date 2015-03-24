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


/* klasa koja sluzi za prikaz sadrzaja prozora */


#include <iostream>
#include "global.h"
#include <cmath>

/* prikazuje sadrzaj prozora */
void Display::show(void)
{
    if(modus==MODUS_MENI)
        Display::meni();
    else if(modus==MODUS_START)
        Display::start();
    else if(modus==MODUS_TEST)
        Display::test();
}


/* prikazuje meni */
void Display::meni()
{
    glut::light(GL_OFF);
    glut::modelView2D();

    glut::color(1,0,0,1);
    glut::pravougaonik(Tacka(1,1,0),Tacka(1,-1,0),Tacka(0,-1,0),Tacka(0,1,0));

    glut::color(1,1,1,1);
    glut::text(0.5,0.5,"Test");
    glut::text(0,0,"Test");
    glut::swapBuffers();
}


/* prikazuje meni->start */
void Display::start()
{
    this->ugao+=0.1;
    glut::light(GL_ON);



    glut::modelView3D(0,0,200);

    glut::color(0,1.0,0,1.0);
    glut::lightPosition(0,0,0,1);
    glut::lookAt(100*std::sin((float)ugao/180*PII), 100, 100*std::cos((float)ugao/180*PII) , 0, 0, 0);


    glut::grid(200, 5, 1.0f, 0.0f, 0.0f);

    /*
    model_1();
    glut::translate(0, 0, 50);
    glut::push();
    glut::rotate(30, 0, 1, 0);
    model_2();
    glut::pop();

    glut::push();
    glut::translate(0, 0, 50);
    
    model_3();

    glut::pop();*/

    robot[PLAYER_1]->draw();
    robot[PLAYER_2]->draw();
    robot[PLAYER_TEST]->draw();

    robot[PLAYER_1]->display3D(45,window_width,window_height,1,1000,GL_ON);


    glut::swapBuffers();
}


void Display::test()
{

    this->ugao++;
    glut::light(GL_ON);

    glut::modelView3D(0,0,100);
    glut::lightPosition(0,0,0,1);
    glut::rotate(30,1,0,0);
    glut::rotate(this->ugao,0,1,0);
    model_3();


    glut::swapBuffers();
}
