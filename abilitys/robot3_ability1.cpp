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
#include "robot3_ability1.h"
#include "ability.h"


/* konstruktor koji prima kolko dugo se ceka za sledece koriscenje,
 * kolko puta se iscrtava po sekundi */
Robot3_ability1::Robot3_ability1(int cooldown,int ticksPerSecond)
    : Ability(cooldown,ticksPerSecond,0 , Tacka(0,0,0) )
{_damage=15;}


/* crtanje ability */
void Robot3_ability1::draw()
{
    /* MELEE ABILITY */
    /* Nozici */

    /* ako je _time veci od 0, onda su nozevi aktivirani */
    if(_time > 0)
    {
        glutcpp::push();
            glutcpp::translate(0,11,0);
            glutcpp::translate(_center);
            glutcpp::color(0.5,0.5,0.5,1);
            glutcpp::rotate(21*_time,0,1,0);

            /* nozici robota */
            for(int i=0;i<8;i++)
            {
                glutcpp::push();
                    glutcpp::rotate(i*45,0,1,0);
                    glutcpp::translate(0,0,15.0*_number);
                    glutcpp::kvadar(Tacka(0,0.5,0),Tacka(0,0.5,0),Tacka(0,0,10),Tacka(5,0.5,0),
                                 Tacka(0,-0.5,0),Tacka(0,-0.5,0),Tacka(0,0,10),Tacka(5,-0.5,0));
                glutcpp::pop();
            }
        glutcpp::pop();
    }

    /* debug crtanje */
    testDraw();
}


/* dodatna izracunvanja za tacku sudara */
void Robot3_ability1::animation2(Tacka _centar_robota, float _ugao_robota)
{
    _center=_centar_robota;
    _ugao=_ugao_robota;

    /* promenljive za poziciju nozveva */
    _number=0;
    if(_time>4*_ticksPerSecond)
        _number=5*_ticksPerSecond-_time;
    else if(_time>3.5*_ticksPerSecond)
        _number=_ticksPerSecond;
    else if(_time>2.5*_ticksPerSecond)
        _number=_time - 2.5*_ticksPerSecond;
    else
        _number=0;
    _number=_number/_ticksPerSecond;

    /* potrebno za koliziju */
    _radius=15.0*_number+10;
}
