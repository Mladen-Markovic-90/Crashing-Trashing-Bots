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


#ifndef ROBOT1_ABILITY1_H
#define ROBOT1_ABILITY1_H


/* Ukljucivanje potrebnih zaglavlja */
#include "ability.h"


/* ovaj ability je cekic za robot 1 */
class Robot1_ability1 : public Ability
{
public:
    /* konstruktor koji prima kolko dugo se ceka za sledece koriscenje,
     * kolko puta se iscrtava po sekundi */
    Robot1_ability1(int cooldown,int ticksPerSecond);

    /* dekonstruktor */
    ~Robot1_ability1() {}

    /* dodatna izracunvanja za tacku sudara */
    void animation2(Tacka _centar_robota, float _ugao_robota);

    /* crtanje ability */
    void draw();
};


#include "robot1_ability1.cpp"


#endif // ROBOT1_ABILITY1_H
