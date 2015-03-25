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


/* Rad sa obicnim karakterima sa tastature */


/* Ukljucivanje potrebnih zaglavlja */
#include "keys.h"
#include "global.h"


/* postavljanje flagova ili radnja za karaktere koja su stisnuta na tastaturi */
void Keys::setKey(unsigned char key, int x, int y) const
{
    if(modus==MODUS_START)
    {
        // roboti[PLAYER_1]->set_key(key);
        // roboti[PLAYER_2]->set_key(key);
	for (vector<Robot*>::iterator it=roboti.begin(); it != roboti.end(); ++it)
	    (*it)->set_key(key);
    }

    switch(key)
    {/*
        case '1':
            modus=MODUS_MENI;
            glut::reshapeWindow(window_width,window_height);
            glut::reDisplay();
            break;
        case '2':
            modus=MODUS_START;
            glut::reshapeWindow(window_width,window_height);
            glut::reDisplay();
            break;*/
        case '0':
            glut::fullScreenToggle();
            break;
    }

}


/* skidanje flagova za karaktere koja su stisnuta na tastaturi */
void Keys::unsetKey(unsigned char key, int x, int y) const
{
    if(modus==MODUS_START)
    {
        // roboti[PLAYER_1]->unset_key(key);
        // roboti[PLAYER_2]->unset_key(key);
	for (vector<Robot*>::iterator it=roboti.begin(); it != roboti.end(); ++it)
	    (*it)->unset_key(key);
    }

}
