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


/* Klasa za robotic 2 i rad sa njim */


/* Ukljucivanje potrebnih zaglavlja */
#include "robot_2.h"
#include <cmath>


/* Konstruktor za robotica 2 */
Robot_2::Robot_2(int player,Tacka t)
    : Robot(player,t,Tacka(0,0,-15),0,5*SECOND,5*SECOND,5*SECOND,5*SECOND)
    {}


// void Robot_2::animation()
// {
//     if(this->_left_right==KEY_LEFT)
//         this->_ugao-=5;
//     else if(this->_left_right==KEY_RIGHT)
//         this->_ugao+=5;

//     if(this->_up_down==KEY_UP)
//         this->_center.add(this->_speed*std::sin(this->_ugao/180*PII),0,-this->_speed*std::cos(this->_ugao/180*PII));
//     else if(this->_up_down==KEY_DOWN)
//         this->_center.add(-this->_speed*std::sin(this->_ugao/180*PII),0,this->_speed*std::cos(this->_ugao/180*PII));

// }


/* Iscrtavanje robotica 2 */
void Robot_2::draw()
{
    glut::push();
        glut::translate(this->_center);
        glut::rotate(-this->_ugao,0,1,0);
        glut::rotate(-90,0,1,0);
        this->model();
    glut::pop();
}


void Robot_2::model()
{

    /* Tockovi */
    glut::push();
        this->ugao_tocak++;
        glut::rotate(180,0,1,0);
        glut::translate(10,5,-10);
        Delovi::tocak(5,2,this->ugao_tocak);
        glut::translate(-20,0,0);
        Delovi::tocak(5,2,this->ugao_tocak);
        glut::translate(0,0,18);
        Delovi::tocak(5,2,this->ugao_tocak);
        glut::translate(20,0,0);
        Delovi::tocak(5,2,this->ugao_tocak);
    glut::pop();

    glut::push();
        glut::color(0.5,0.5,0.5,1);
        glut::translate(0,6,0);
        glut::kvadar(10,20,8);
    glut::pop();

    glut::push();
        glut::color(0.5,0.5,1,1);
        glut::translate(0,10,0);
        glut::kvadar(Tacka(-15,0,10),Tacka(15,0,10),Tacka(15,0,-10),Tacka(-15,0,-10),
                     Tacka(0,5,5),Tacka(20,5,5),Tacka(20,5,-5),Tacka(0,5,-5));

    glut::pop();

    glut::push();
        glut::color(0.2,0.2,0.2,1);
        glut::translate(17,13,3);
        glut::rotate(90,0,1,0);
        glut::cylinder(1,5);
        glut::rotate(-90,0,1,0);
        glut::translate(0,0,-6);
        glut::rotate(90,0,1,0);
        glut::cylinder(1,5);
    glut::pop();
}
