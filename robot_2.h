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


/* Klasa za robotic 2 i rad sa njim */


#ifndef ROBOT_2_H
#define ROBOT_2_H


/* Ukljucivanje potrebnih zaglavlja */
#include "robot.h"


class Robot_2 : public Robot
{
public:

    /* Konstruktor za robotica 2 */
    Robot_2(int player=PLAYER_2,Tacka t=Tacka(0,0,0));

    /* virtual void animation(); */

    /* Iscrtavanje robotica 2 */
    virtual void draw();
};


#endif // ROBOT_2_H
