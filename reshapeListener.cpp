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


/* ukljucujemo potrebna zaglavlja */
#include "global.h"


/* Obrada prikaza za prozor u zavisnosti od modusa */
void reshapeListener::reshape(int width, int height)
{
    windowWidth=width;
    windowHeight=height;
    if(modus==MODUS_MENI)
        glutcpp::projection2D(width,height);
    else if(modus==MODUS_ARENA || modus==MODUS_TEST_MLADEN)
        glutcpp::projection3D(width,height,45,1,1000);
}
