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


#ifndef ROBOT_1_H
#define ROBOT_1_H


/* Ukljucivanje potrebnih zaglavlja */
#include "robot.h"
#include "abilitys/robot1_ability1.h"
#include "abilitys/robot1_ability2.h"

/* klasa za robotic 1 */
class Robot_1 : public Robot
{
public:

    /* Konstruktor za robotica 1 */
    Robot_1(float ticksPerSecond,int player=PLAYER_NONE,Tacka t=Tacka(0,0,0));

    /* Dekonstruktor */
    ~Robot_1(){}

    /* Iscrtavanje robotica 1 */
    virtual void draw();

private:

    /* Model robotica 1 */
    void model();

    /* DEFENSIVE ABILITY */
    /* Energetski Shield */
    void ability_3();

    /* sluzi za rotaciju tockova */
    int ugao_rotacije_tocak=0;

};


#include "robot_1.cpp"


#endif // ROBOT_1_H
