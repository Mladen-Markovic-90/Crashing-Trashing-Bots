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


#ifndef ROBOT3_ABILITY1_H
#define ROBOT3_ABILITY1_H

#include "ability.h"

class Robot3_ability1 : public Ability
{
public:
    Robot3_ability1(int cooldown,int ticksPerSecond);
    ~Robot3_ability1() {}
    void animation2(Tacka _centar_robota, float _ugao_robota);
    void draw();
};

#include "robot3_ability1.cpp"

#endif // ROBOT3_ABILITY1_H
