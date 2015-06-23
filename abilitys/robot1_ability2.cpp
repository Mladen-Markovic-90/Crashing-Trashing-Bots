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


#include "robot1_ability2.h"
#include "../provera.h"


Robot1_ability2::Robot1_ability2(int cooldown,int ticksPerSecond)
    : Ability(cooldown,ticksPerSecond,-1 , Tacka(20,0,0))
{_damage=25;}


void Robot1_ability2::draw()
{
    if(_time <= 0 || _exist==false)
        return;
    //NOTE: tacka udarca -> this->tacka_raketa + Tacka(20,0,0);
    /* RANGE ABILITY */
    /* Raketa */

    /* pozicija i ugao rakete *//*
    float number=0;
    if(_time>0)
        number=5*_ticksPerSecond-_time;*/
    /*else
    {
        _ugao=_ugao_robota-90;
        this->tacka_raketa_help=_centar_robota;
    }*/

    //number*=10;
    //this->tacka_raketa=Tacka(20,0,0)+Tacka(1,0,0)*number;

    glutcpp::push();
        /* postavljamo raketu na odredjeno mesto */
        //glutcpp::translate(this->tacka_raketa_help);
        glutcpp::translate(0,5,0);


        glutcpp::translate(_center);
        //glutcpp::translate(Tacka(-20,0,0));

        glutcpp::rotate(-_ugao,0,1,0);

        /* ako je number vece od 0, onda se raketa krece i izbacuje vatru */
        if(_time>0)
        {
            glutcpp::color(1,0.5,0,0.5);
            for(int i=0;i<25;i++)
            {
                float x=((float)std::rand()/RAND_MAX)*5.0;
                float y=-3+((float)std::rand()/RAND_MAX)*6.0;
                float c=-1+((float)std::rand()/RAND_MAX)*2.0;
                glutcpp::linija(Tacka(-x,-y,0),Tacka(-(3+x),-(y+c),0));
            }
        }

        /* Raketa */
        glutcpp::rotate(90,0,1,0);
        glutcpp::color(0.5,0.5,0.5,1);
        glutcpp::cylinder(3,15);
        glutcpp::rotate(-90,0,1,0);
        glutcpp::translate(15,0,0);
        glutcpp::rotate(90,0,1,0);
        glutcpp::color(1,0,0,0.8);
        glutcpp::cone(5,6);

    glutcpp::pop();

    testDraw();

}


void Robot1_ability2::animation2(Tacka _centar_robota, float _ugao_robota)
{
    float number=0;
    if(_time>0)
        number=5*_ticksPerSecond-_time;
    else
    {
        this->_ugao=_ugao_robota-90;
        this->_center=_centar_robota;
    }

    number*=1.5;
    //this->tacka_raketa=Tacka(20,0,0)+Tacka(1,0,0)*number;

    this->_center=this->_center+provera::position(Tacka(20,0,0)+Tacka(1,0,0)*number,Tacka(0,0,0),_ugao);
}
