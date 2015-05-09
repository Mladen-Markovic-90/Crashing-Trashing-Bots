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


/* Ukljucivanje potrebnih zaglavlja */
#include "global.h"


/* Funkcija za timer i izracunavanje */
void animationTimer::timer(int id) const
{
    id=id;

    /* pokrecemo animaciju za svakog robota */
    if(status.modus==MODUS_ARENA || status.modus==MODUS_TEST_MLADEN)
    {
        for(Robot * item : roboti)
            item->animation();
    }

    glutcpp::reDisplay();
}
