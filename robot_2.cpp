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


/* Konstruktor za robotica 2 */
Robot_2::Robot_2(float ticksPerSecond,int player, Tacka t)
    : Robot(ticksPerSecond,player,t,Tacka(0,0,-15),0,
            5*ticksPerSecond,5*ticksPerSecond,5*ticksPerSecond,5*ticksPerSecond,
            Tacka(-10,0,-15),Tacka(10,0,-15),Tacka(10,0,15),Tacka(-10,0,15),15)
{}


/* Iscrtavanje robotica 2 */
void Robot_2::draw()
{
    this->model();
    this->ability_1();
    this->ability_2();
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


/* NOTE tacka udarca provera::position(tacka_kolac,_center,_ugao) */
/* MELEE ABILITY */
/* Kolac */
void Robot_2::ability_1()
{


    /* promenljive za poziciju nozveva */
    float number=0;
    if(this->_ability_1>4*_ticksPerSecond)
        number=5*_ticksPerSecond-this->_ability_1;
    else if(this->_ability_1>3.5*_ticksPerSecond)
        number=_ticksPerSecond;
    else if(this->_ability_1>2.5*_ticksPerSecond)
        number=this->_ability_1 - 2.5*_ticksPerSecond;
    else
        number=0;
    number=number/_ticksPerSecond;

    number*=15;
    /* potrebno za koliziju */
    //this->tacka_kolac=this->_center+Tacka(0,0,-1)*number;
    this->tacka_kolac=Tacka(0,0,-15)+Tacka(0,0,-1)*number;

    if(number>-1)
    {
        glutcpp::push();
            /* postavljamo laser na odredjeno mesto */
            glutcpp::translate(_center);
            glutcpp::translate(0,5,0);

            glutcpp::rotate(-this->_ugao,0,1,0);
            glutcpp::translate(this->tacka_kolac);
            glutcpp::translate(Tacka(0,0,15));


            /* Laser */
            glutcpp::color(0.5,0.5,0.5,1);
            glutcpp::rotate(180,0,1,0);
            glutcpp::cone(3,15);

        glutcpp::pop();
    }

    /*test*//*
    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(provera::position(tacka_kolac,_center,_ugao));
        glutcpp::cube(5);
    glutcpp::pop();*/

}


/* NOTE tacka udarca provera::position(tacka_laser,tacka_laser_help,ugao_laser) */
/* RANGE ABILITY */
/* Raketa */
void Robot_2::ability_2()
{
    /* pozicija i ugao rakete */
    float number=0;
    if(this->_ability_2>0)
        number=5*_ticksPerSecond-this->_ability_2;
    else
    {
        this->ugao_laser=this->_ugao-90;
        this->tacka_laser_help=_center;
    }

    number*=10;
    this->tacka_laser=Tacka(15,0,0)+Tacka(1,0,0)*number;

    if(number>0)
    {
        glutcpp::push();
            /* postavljamo laser na odredjeno mesto */
            glutcpp::translate(this->tacka_laser_help);
            glutcpp::translate(0,5,0);

            glutcpp::rotate(-this->ugao_laser,0,1,0);
            glutcpp::translate(tacka_laser);
            glutcpp::translate(Tacka(-15,0,0));


            /* Laser */
            glutcpp::rotate(90,0,1,0);
            glutcpp::color(0.5,0.5,2,1);
            glutcpp::cylinder(0.5,15);

        glutcpp::pop();
    }


    /*test*//*
    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(provera::position(tacka_laser,tacka_laser_help,ugao_laser));
        glutcpp::cube(5);
    glutcpp::pop();

    glutcpp::push();
        glutcpp::color(1,0,0,1);
        glutcpp::translate(_center);
        glutcpp::cube(5);
    glutcpp::pop();*/
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
