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

#include "robot3_ability2.h"
#include "ability.h"

Robot3_ability2::Robot3_ability2(int cooldown,int ticksPerSecond)
    : Ability(cooldown,ticksPerSecond,0 , Tacka(0,0,0) )
{_damage=10;}



void Robot3_ability2::draw()
{
    if(_exist==false)
        return;

    /* promenljiva potrebna za koliziju */
    //this->_radius_laser=0;

    /* laser traje kratko */
    if(_time > 4.5*_ticksPerSecond)
    {
        /* laser - velicina u zavisnosti od tikova */
        glutcpp::push();
            glutcpp::color(0,1,0,_number-0.2);
            glutcpp::translate(0,10,0);
            glutcpp::translate(_center);
            glutcpp::rotate(90,1,0,0);
            glutcpp::cylinder((1.0-_number)*1000,1);
        glutcpp::pop();

    }

    /* test *//*
    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(0,5,0);
        glutcpp::translate(Tacka(-_radius_laser,0,0));
        glutcpp::cube(5);
    glutcpp::pop();*/



}


void Robot3_ability2::animation2(Tacka _centar_robota, float _ugao_robota)
{
    _center=_centar_robota;
    _ugao=_ugao_robota;

    _radius=0;

    if(_time > 4.5*_ticksPerSecond)
        {
        _number=(float)_time/_cooldown;
        /* za koliziju */
        _radius=(1.0-_number)*1000;
        }


}
