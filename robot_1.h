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


/* Klasa za robotic 1 i rad sa njim */


#ifndef ROBOT_1_H
#define ROBOT_1_H


/* Ukljucivanje potrebnih zaglavlja */
#include "robot.h"


class Robot_1 : public Robot
{
public:

    /* Konstruktor za robotica 1 */
    Robot_1(int player=PLAYER_NONE,Tacka t=Tacka(0,0,0));

    /* virtual void animation(); */


    /* Iscrtavanje robotica 1 */
    virtual void draw();

private:

    /* Model robotica 1 */
    void model();


    /* Ability 1 robotica 1 */
    /* Ability 1 je udaranje cekicem */
    /* MELEE ABILITY */
    void ability_1();

    /* RANGE ABILITY */
    void ability_2();

    /* DEFENSIVE ABILITY */
    void ability_3();

    /* SPECIAL ABILITY */
    void ability_4();


    int ugao_tocak=0;

    Tacka tacka_raketa=Tacka(0,0,0);
    int ugao_raketa=0;
};


#endif // ROBOT_1_H
