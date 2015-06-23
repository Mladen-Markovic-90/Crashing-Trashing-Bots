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

#ifndef ROBOT2_ABILITY1_H
#define ROBOT2_ABILITY1_H

#include "ability.h"

class Robot2_ability1 : public Ability
{
public:
    Robot2_ability1(int cooldown,int ticksPerSecond);
    ~Robot2_ability1() {}

    void animation2(Tacka _centar_robota, float _ugao_robota);
    void draw();

private:
    /* sluzi za poziciju udarca kolca */
    Tacka tacka_kolac=Tacka(0,0,0);
};


#include "robot2_ability1.cpp"

#endif // ROBOT2_ABILITY1_H
