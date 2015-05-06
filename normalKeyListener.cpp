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
#include "normalKeyListener.h"
#include "global.h"


/* postavljanje flagova ili radnja za karaktere koja su stisnuta na tastaturi */
void normalKeyListener::keyDown(unsigned char normalKey, int x, int y) const
{
    x=x;y=y;
    if(modus==MODUS_ARENA || modus==MODUS_TEST_MLADEN)
    {
        for(Robot * item : roboti)
            if(item->getPlayer()!=PLAYER_NONE)
                item->set_key(normalKey);
    }

}


/* skidanje flagova za karaktere koja su stisnuta na tastaturi */
void normalKeyListener::keyUp(unsigned char normalKey, int x, int y) const
{
    x=x;y=y;
    if(modus==MODUS_ARENA || modus==MODUS_TEST_MLADEN)
    {
        for(Robot * item : roboti)
            if(item->getPlayer()!=PLAYER_NONE)
                item->unset_key(normalKey);
    }

}
