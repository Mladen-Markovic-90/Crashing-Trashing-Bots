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
#include "glutcpp/glutcpp.h"
#include <cmath>
#include <iostream>
#include "abilitys/ability.h"
#include "abilitys/robot3_ability1.h"
#include "abilitys/robot3_ability2.h"
#include "robot.h"
#include "robot_3.h"
#include "vektor3d.h"

/* Konstruktor za robotica 3 */
Robot_3::Robot_3(float ticksPerSecond, int player, Tacka t)
    : Robot(ticksPerSecond,player,t,Tacka(0,0,-15),0,5*ticksPerSecond,
            Tacka(0,0,-15),Tacka(15,0,0),Tacka(0,0,15),Tacka(-15,0,0),15,100)
{
    _ability01=new Robot3_ability1();//100,20);//5*ticksPerSecond,ticksPerSecond);
    _ability02=new Robot3_ability2();//100,20);//5*ticksPerSecond,ticksPerSecond);
}


/* Iscrtavanje robotica 3 */
void Robot_3::draw()
{
    this->model();
    _ability01->draw();
    _ability02->draw();
    this->ability_3();
}


/* Model robotica 3 */
void Robot_3::model()
{
    glutcpp::push();
        glutcpp::translate(this->_center);
        /* robotic se uvek okrece */
        glutcpp::rotate(21*this->_ugao_rotacije,0,-1,0);

        this->_ugao_rotacije++;

        /* donji deo robotica */
        glutcpp::push();
            glutcpp::color(0.5,0.5,0.5,this->_fade);
            glutcpp::translate(0,10,0);
            glutcpp::rotate(90,1,0,0);
            glutcpp::cone(15,15);
        glutcpp::pop();

        /* dekoracija kod donjeg dela robotica */
        glutcpp::push();
            glutcpp::color(0.5,0.5,0.5,this->_fade);
            glutcpp::kvadar(Tacka(5,0,5),Tacka(-5,0,5),Tacka(-5,0,-5),Tacka(5,0,-5),
                         Tacka(5,1,5),Tacka(-5,1,5),Tacka(-5,1,-5),Tacka(5,1,-5));
            glutcpp::rotate(45,0,1,0);
            glutcpp::kvadar(Tacka(5,0,5),Tacka(-5,0,5),Tacka(-5,0,-5),Tacka(5,0,-5),
                         Tacka(5,1,5),Tacka(-5,1,5),Tacka(-5,1,-5),Tacka(5,1,-5));
        glutcpp::pop();

        /* gornji deo robotica */
        glutcpp::push();
            glutcpp::color(0.1,0.1,0.1,this->_fade);
            glutcpp::translate(0,12,0);
            glutcpp::rotate(90,1,0,0);
            glutcpp::cylinder(15,2);
        glutcpp::pop();
    glutcpp::pop();
}


/* DEFENSIVE ABILITY */
/* Fade Shield */
void Robot_3::ability_3()
{
    /* odredjivanje providnosti robotica */
    this->_fade=1.0;
    if(this->_ability_3 > 0)
    {
        float number=(float)this->_ability_3/this->_ability_3_cooldown;
        number=number/2.0;
        this->_fade=1.0-number;
    }
}


// /* SPECIAL ABILITY */
// /* Speed + Lava nozevi */
// void Robot_3::ability_4()
// {
//     /* ako je aktiviran ability 4 */
//     if(this->_ability_4 > 0)
//     {
//         /* povecavamo brzinu i postavljamo nozeve na lava (crvenu boju) */
//         _speed= 200 * Vektor3D::rotate2D(Tacka(1/_ticksPerSecond, 0, 0), _ugao);
	
//         this->_lava=true;
	
//         /* postavljamo ability 1 na odredjen broj, jer ability 4 koristi ability 1 samo pojacan */
//         this->_ability_1=4*_ticksPerSecond;
//     }
//     else
//     {
//         _speed= 100 * Vektor3D::rotate2D(Tacka(1/_ticksPerSecond, 0, 0), _ugao);
// 	//        this->_speed=100/_ticksPerSecond;
//         this->_lava=false;
//     }
// }

