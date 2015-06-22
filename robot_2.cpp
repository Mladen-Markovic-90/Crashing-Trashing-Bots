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
#include <cmath>
#include "abilitys/robot2_ability1.h"
#include "abilitys/robot2_ability2.h"
#include "abilitys/ability.h"


/* Konstruktor za robotica 2 */
Robot_2::Robot_2(float ticksPerSecond,int player, Tacka t)
    : Robot(ticksPerSecond,player,t,Tacka(0,0,-15),0,5*ticksPerSecond,
            Tacka(-10,0,-15),Tacka(10,0,-15),Tacka(10,0,15),Tacka(-10,0,15),15)
{

    _ability01=new Robot2_ability1();//100,20);//5*ticksPerSecond,ticksPerSecond);
    _ability02=new Robot2_ability2();//100,20);//5*ticksPerSecond,ticksPerSecond);
}


/* Iscrtavanje robotica 2 */
void Robot_2::draw()
{
    this->model();
    _ability01->draw();
    _ability02->draw();
    this->ability_3();
}


void Robot_2::model()
{
    glutcpp::push();

        glutcpp::translate(this->_center);
        glutcpp::rotate(-this->_ugao,0,1,0);
        glutcpp::rotate(-90,0,1,0);
        /* kako ce biti okrenuti tockovi u zavisnosti od pravca kretanja */
        int ugao_tocak=0;
        if(this->_left_right==KEY_LEFT)
            ugao_tocak=30;
        else if(this->_left_right==KEY_RIGHT)
            ugao_tocak=-30;

        /* Tockovi */
        glutcpp::push();
            this->ugao_tocak++;
            glutcpp::rotate(180,0,1,0);
            glutcpp::translate(10,5,-10);
            Delovi::tocak(5,2,this->ugao_tocak,ugao_tocak);
            glutcpp::translate(-20,0,0);
            Delovi::tocak(5,2,this->ugao_tocak,0);
            glutcpp::translate(0,0,18);
            Delovi::tocak(5,2,this->ugao_tocak,0);
            glutcpp::translate(20,0,0);
            Delovi::tocak(5,2,this->ugao_tocak,ugao_tocak);
        glutcpp::pop();

        /* popunjavanje kod tockova */
        glutcpp::push();
            glutcpp::color(0.5,0.5,0.5,1);
            glutcpp::translate(0,6,0);
            glutcpp::kvadar(10,20,8);
            glutcpp::translate(-5,0,0);
            glutcpp::kvadar(20,10,8);
        glutcpp::pop();

        /* glavni deo robotica */
        glutcpp::push();
            glutcpp::color(0.5,0.5,1,1);
            glutcpp::translate(0,10,0);
            glutcpp::kvadar(Tacka(-15,0,10),Tacka(15,0,10),Tacka(15,0,-10),Tacka(-15,0,-10),
                         Tacka(0,5,5),Tacka(20,5,5),Tacka(20,5,-5),Tacka(0,5,-5));

        glutcpp::pop();

        /* auspuh nazad */
        glutcpp::push();
            glutcpp::color(0.2,0.2,0.2,1);
            glutcpp::translate(17,13,3);
            glutcpp::rotate(90,0,1,0);
            glutcpp::cylinder(1,5);
            glutcpp::rotate(-90,0,1,0);
            glutcpp::translate(0,0,-6);
            glutcpp::rotate(90,0,1,0);
            glutcpp::cylinder(1,5);
        glutcpp::pop();

    glutcpp::pop();
}

/* DEFENSIVE ABILITY */
/* Energetski Shield */
void Robot_2::ability_3()
{
    float number=this->_ability_3/(float)this->_ability_3_cooldown;
    if(this->_ability_3 > 0)
    {
        glutcpp::push();
            glutcpp::translate(this->_center);
            glutcpp::rotate(-this->_ugao,0,1,0);
            glutcpp::rotate(-90,0,1,0);

            glutcpp::color(1,1,1,0.8*number);
            glutcpp::translate(5,10,0);
            glutcpp::kvadar(45,30,20);
        glutcpp::pop();
    }
}
