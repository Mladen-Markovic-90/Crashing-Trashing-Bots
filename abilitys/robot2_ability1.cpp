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


#include "robot2_ability1.h"
#include "../provera.h"

Robot2_ability1::Robot2_ability1(int cooldown,int ticksPerSecond)
    : Ability(cooldown,ticksPerSecond,-1 , Tacka(0,0,0) )
{_damage=15;}


void Robot2_ability1::draw()
{
    /* NOTE tacka udarca provera::position(tacka_kolac,_center,_ugao) */
    /* MELEE ABILITY */
    /* Kolac */

    if(_time <= 0)
        return;

    /* promenljive za poziciju nozveva */
    float number=0;
    if(_time>4*_ticksPerSecond)
        number=5*_ticksPerSecond-_time;
    else if(_time>3.5*_ticksPerSecond)
        number=_ticksPerSecond;
    else if(_time>2.5*_ticksPerSecond)
        number=_time - 2.5*_ticksPerSecond;
    else
        number=0;
    number=number/_ticksPerSecond;

    number*=15;
    /* potrebno za koliziju */
    //this->tacka_kolac=this->_center+Tacka(0,0,-1)*number;
    //this->tacka_kolac=Tacka(0,0,-15)+Tacka(0,0,-1)*number;

    if(number>-1)
    {
        glutcpp::push();
            /* postavljamo laser na odredjeno mesto */
            glutcpp::translate(0,5,0);

            glutcpp::translate(_center);

            glutcpp::rotate(-_ugao,0,1,0);

            glutcpp::translate(Tacka(0,0,15));


            /* Kolac */
            glutcpp::color(0.5,0.5,0.5,1);
            glutcpp::rotate(180,0,1,0);
            glutcpp::cone(3,15);

        glutcpp::pop();
    }

    this->testDraw();

    /*test*//*
    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(provera::position(tacka_kolac,_center,_ugao));
        glutcpp::cube(5);
    glutcpp::pop();*/
}



void Robot2_ability1::animation2(Tacka _centar_robota, float _ugao_robota)
{
    float number=0;
    if(_time>4*_ticksPerSecond)
        number=5*_ticksPerSecond-_time;
    else if(_time>3.5*_ticksPerSecond)
        number=_ticksPerSecond;
    else if(_time>2.5*_ticksPerSecond)
        number=_time - 2.5*_ticksPerSecond;
    else
        number=0;
    number=number/_ticksPerSecond;

    number*=15;
    /* potrebno za koliziju */

    this->_center=_centar_robota+provera::position(Tacka(0,0,-15)+Tacka(0,0,-1)*number,Tacka(0,0,0),_ugao);

    this->_ugao=_ugao_robota;
}
