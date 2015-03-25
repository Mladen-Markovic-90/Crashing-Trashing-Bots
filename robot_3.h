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


/* Klasa za robotic 3 i rad sa njim */


#ifndef ROBOT_3_H
#define ROBOT_3_H


/* Ukljucivanje potrebnih zaglavlja */
#include "robot.h"


class Robot_3 : public Robot
{
public:

    /* Konstruktor za robotica 3 */
    Robot_3(int player=PLAYER_TEST,Tacka t=Tacka(0,0,0));

    /* Animacija i izracunavanje za robotic 3, izvrsava se u klasi timer */
    virtual void animation();

    /* Iscrtavanje robotica 3 */
    virtual void draw();

    /* Model robotica 3 */
    void model();

    /* Ability 1 robotica 3 */
    /* Ability 1 je izbacivanje nozica */
    void ability_1();

private:

    /* Rotacija robotica 3 oko svoje ose, za animaciju */
    int _ugao_rotacije;
};


#endif // ROBOT_3_H
