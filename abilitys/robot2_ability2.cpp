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
#include "robot2_ability2.h"
#include "../provera.h"


/* konstruktor koji prima kolko dugo se ceka za sledece koriscenje,
 * kolko puta se iscrtava po sekundi */
Robot2_ability2::Robot2_ability2(int cooldown,int ticksPerSecond)
    : Ability(cooldown,ticksPerSecond,-1 , Tacka(15,0,0))
{_damage=20;}


/* crtanje ability */
void Robot2_ability2::draw()
{
    /* RANGE ABILITY */
    /* Raketa */

    if(_time <= 0 || _exist==false)
        return;

    glutcpp::push();
        /* postavljamo laser na odredjeno mesto */
        glutcpp::translate(0,5,0);
        glutcpp::translate(this->_center);

        glutcpp::rotate(-_ugao,0,1,0);

        /* Laser */
        glutcpp::rotate(90,0,1,0);
        glutcpp::color(0.5,0.5,2,1);
        glutcpp::cylinder(0.5,15);

    glutcpp::pop();

    testDraw();
}


/* dodatna izracunvanja za tacku sudara */
void Robot2_ability2::animation2(Tacka _centar_robota, float _ugao_robota)
{
    _number=0;
    if(_time>0)
        _number=5*_ticksPerSecond-_time;
    else
    {
        this->_ugao=_ugao_robota-90;
        this->_center=_centar_robota;
    }

    this->_center=this->_center+provera::position(Tacka(15,0,0)+Tacka(1,0,0)*_number,Tacka(0,0,0),_ugao);

}
