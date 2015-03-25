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


/* Rad sa specijalnim karakterima sa tastature */


/* ukljucivanje potrebnih zaglavlja */
#include "special_keys.h"
#include "global.h"


/* postavljanje flagova ili radnja za specijalne karaktere koja su stisnuta na tastaturi */
void Special_keys::setKey(int key, int x, int y) const
{
    // if(modus==MODUS_ARENA)
    //     roboti[PLAYER_TEST]->set_key(key);
    if(modus==MODUS_TEST_MLADEN)
        for(Robot * item : roboti)
            if(item->getPlayer()==PLAYER_TEST)
                item->set_key(key);

    switch(key)
    {
    case GLUT_KEY_F11:
        glut::fullScreenToggle();
        break;
    }

}


/* skidanje flagova za specijalne karaktere koja su stisnuta na tastaturi */
void Special_keys::unsetKey(int key, int x, int y) const
{
    // if(modus==MODUS_ARENA)
    //     roboti[PLAYER_TEST]->unset_key(key);
    if(modus==MODUS_TEST_MLADEN)
        for(Robot * item : roboti)
            if(item->getPlayer()==PLAYER_TEST)
                item->unset_key(key);

}
