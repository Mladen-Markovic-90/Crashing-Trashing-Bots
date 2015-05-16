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


#ifndef ROBOT_2_H
#define ROBOT_2_H


/* Ukljucivanje potrebnih zaglavlja */
#include "robot.h"


/* Klasa za robotic 2 */
class Robot_2 : public Robot
{
public:
    /* Konstruktor za robotica 2 */
    Robot_2(float ticksPerSecond,int player=PLAYER_NONE,Tacka t=Tacka(0,0,0));

    /* Dekonstruktor */
    ~Robot_2(){}

    /* Iscrtavanje robotica 2 */
    virtual void draw();

private:

    /* Model robotica 2 */
    void model();

    /* MELEE ABILITY */
    /* Kolac */
    void ability_1();

    /* RANGE ABILITY */
    /* Laser */
    void ability_2();

    /* DEFENSIVE ABILITY */
    /* Energetski Shield */
    void ability_3();

    /* sluzi za rotaciju tockova */
    int ugao_tocak=0;

    /* sluzi za poziciju i rotaciju lasera */
    Tacka tacka_laser=Tacka(0,0,0);
    Tacka tacka_laser_help=_center;
    int ugao_laser=0;

    /* sluzi za poziciju udarca kolca */
    Tacka tacka_kolac=Tacka(0,0,0);
};


#include "robot_2.cpp"


#endif // ROBOT_2_H
