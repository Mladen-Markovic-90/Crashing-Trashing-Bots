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


#ifndef ROBOT1_ABILITY2_H
#define ROBOT1_ABILITY2_H

#include "ability.h"

class Robot1_ability2 : public Ability
{
public:
    Robot1_ability2(int cooldown,int ticksPerSecond);
    ~Robot1_ability2() {}

    void draw();

    void animation2(Tacka _centar_robota, float _ugao_robota);
private:
    /* sluzi za poziciju i rotaciju rakete */
    Tacka tacka_raketa=Tacka(0,0,0);
    Tacka tacka_raketa_help=Tacka(0,0,0);
    int ugao_raketa=0;
};


#include "robot1_ability2.cpp"

#endif // ROBOT1_ABILITY2_H
