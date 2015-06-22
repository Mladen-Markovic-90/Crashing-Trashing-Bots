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


/* Ukljucivanje potrebnih zaglavlja */
#include "delovi.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "provera.h"
#include "abilitys/ability.h"
#include "abilitys/robot1_ability1.h"
#include "abilitys/robot1_ability2.h"


/* Konstruktor za robotica 1 */
Robot_1::Robot_1(float ticksPerSecond,int player,Tacka t)
    : Robot(ticksPerSecond,player,t,Tacka(0,0,-20),0,
            5*ticksPerSecond,5*ticksPerSecond,5*ticksPerSecond,5*ticksPerSecond,
            Tacka(-15,0,-20),Tacka(15,0,-20),Tacka(15,0,20),Tacka(-15,0,20),20)
{
    _ability01=new Robot1_ability1();
    _ability02=new Robot1_ability2();
}

/* Iscrtavanje robotica 1 */
void Robot_1::draw()
{
    this->model();
    _ability01->draw();
    _ability02->draw();

    //this->ability_1();
    //this->ability_2();
    this->ability_3();
}


/* Model robotica 1 */
void Robot_1::model()
{
    glutcpp::push();
        glutcpp::translate(this->_center);
        glutcpp::rotate(-this->_ugao,0,1,0);
        glutcpp::rotate(90,0,1,0);
        /* kako ce biti okrenuti tockovi u zavisnosti od pravca kretanja */
        int ugao_tocak=0;
        if(this->_left_right==KEY_LEFT)
            ugao_tocak=30;
        else if(this->_left_right==KEY_RIGHT)
            ugao_tocak=-30;

        /* tockovi */
        this->ugao_rotacije_tocak++;
        glutcpp::push();
            glutcpp::translate(15,5,-15);
            Delovi::tocak(5,2,this->ugao_rotacije_tocak,ugao_tocak);
            glutcpp::translate(-30,0,0);
            Delovi::tocak(5,2,this->ugao_rotacije_tocak,0);
            glutcpp::translate(0,0,28);
            Delovi::tocak(5,2,this->ugao_rotacije_tocak,0);
            glutcpp::translate(30,0,0);
            Delovi::tocak(5,2,this->ugao_rotacije_tocak,ugao_tocak);
        glutcpp::pop();

        /* popunjavanje kod tockova */
        glutcpp::push();
            glutcpp::color(0.5,0.5,0.5,1);
            glutcpp::translate(0,6,0);
            glutcpp::kvadar(20,30,8);
        glutcpp::pop();

        /* glavni deo robotica */
        glutcpp::push();
            glutcpp::color(0.5,0.5,0,1);
            glutcpp::translate(5,10,0);
            glutcpp::kvadar(Tacka(-25,0,15),Tacka(15,0,15),Tacka(15,0,-15),Tacka(-25,0,-15),
                         Tacka(-30,5,10),Tacka(10,5,10),Tacka(10,5,-10),Tacka(-30,5,-10));
        glutcpp::pop();
    glutcpp::pop();
}

/* DEFENSIVE ABILITY */
/* Energetski Shield */
void Robot_1::ability_3()
{
    float number=this->_ability_3/(float)this->_ability_3_cooldown;
    if(this->_ability_3)
    {
        glutcpp::push();
            glutcpp::translate(this->_center);
            glutcpp::rotate(-this->_ugao,0,1,0);
            glutcpp::rotate(90,0,1,0);

            glutcpp::color(1,1,1,0.8*number);
            glutcpp::translate(-2.5,10,0);
            glutcpp::kvadar(50,30,20);
        glutcpp::pop();
    }
}
