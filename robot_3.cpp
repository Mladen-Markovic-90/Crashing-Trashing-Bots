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


/* Klasa za robotic 3 i rad sa njim */


/* Ukljucivanje potrebnih zaglavlja */
#include "robot_3.h"
#include "model_3.h"
#include "glut.h"
#include <cmath>


/* Konstruktor za robotica 3 */
Robot_3::Robot_3(int player,Tacka t)
    : Robot(player,t,t+Tacka(0,0,0),0,5*SECOND,5*SECOND,5*SECOND,5*SECOND)
    {}


/* Animacija i izracunavanje za robotic 3, izvrsava se u klasi timer */
void Robot_3::animation()
{
    if(this->_ability_1>0)
        this->_ability_1--;
    if(this->_ability_2>0)
        this->_ability_2--;
    if(this->_ability_3>0)
        this->_ability_3--;
    if(this->_ability_4>0)
        this->_ability_4--;
    if(this->_left_right==KEY_LEFT)
        this->_center.add(-this->_speed,0,0);
    else if(this->_left_right==KEY_RIGHT)
        this->_center.add(this->_speed,0,0);

    if(this->_up_down==KEY_UP)
        this->_center.add(0,0,-this->_speed);

    else if(this->_up_down==KEY_DOWN)
        this->_center.add(0,0,this->_speed);

}


/* Iscrtavanje robotica 3 */
void Robot_3::draw()
{
    glut::push();
        glut::translate(this->_center);
        this->model();
        this->ability_1();
    glut::pop();
}


/* Model robotica 3 */
void Robot_3::model()
{
    this->_ugao_rotacije++;

    glut::rotate(21*this->_ugao_rotacije,0,-1,0);
    glut::push();
        glut::color(0.5,0.5,0.5,1);
        glut::translate(0,10,0);
        glut::rotate(90,1,0,0);
        glut::cone(15,15);
    glut::pop();

    glut::push();
        glut::kvadar(Tacka(5,0,5),Tacka(-5,0,5),Tacka(-5,0,-5),Tacka(5,0,-5),
                     Tacka(5,1,5),Tacka(-5,1,5),Tacka(-5,1,-5),Tacka(5,1,-5));
        glut::rotate(45,0,1,0);
        glut::kvadar(Tacka(5,0,5),Tacka(-5,0,5),Tacka(-5,0,-5),Tacka(5,0,-5),
                     Tacka(5,1,5),Tacka(-5,1,5),Tacka(-5,1,-5),Tacka(5,1,-5));
    glut::pop();


    glut::push();
        glut::color(0.1,0.1,0.1,1);
        glut::translate(0,12,0);
        glut::rotate(90,1,0,0);
        glut::cylinder(15,2);
    glut::pop();

}


/* Ability 1 robotica 3 */
/* Ability 1 je izbacivanje nozica */
void Robot_3::ability_1()
{
    float number=0;
    if(this->_ability_1>80)
        number=5.0-this->_ability_1/20.0;
    else if(this->_ability_1>70)
        number=1.0;
    else if(this->_ability_1>50)
        number=this->_ability_1/20.0 - 2.5;
    else
        number=0.0;

    glut::push();
        glut::translate(0,11,0);
        glut::color(0.5,0.5,0.5,1);
        for(int i=0;i<8;i++)
        {
            glut::push();
            glut::rotate(i*45,0,1,0);
            glut::translate(0,0,15*number);
            glut::kvadar(Tacka(0,0.5,0),Tacka(0,0.5,0),Tacka(0,0,10),Tacka(5,0.5,0),
                         Tacka(0,-0.5,0),Tacka(0,-0.5,0),Tacka(0,0,10),Tacka(5,-0.5,0));
            glut::pop();
        }

    glut::pop();


}
