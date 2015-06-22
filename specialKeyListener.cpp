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


/* ukljucivanje potrebnih zaglavlja */
#include "global.h"


/* postavljanje flagova ili radnja za specijalne karaktere koja su stisnuta na tastaturi */
void SpecialKeyListener::keyDown(int key, int x, int y) const
{
    x=x;y=y;
    if(status.modus==MODUS_ARENA)
        for(Robot * item : roboti)
        {
            if(item->getPlayer()==PLAYER_2)
                item->set_key(key);
        }
    else if(status.modus==MODUS_MENI)
        switch(key)
        {
        case GLUT_KEY_DOWN:
            status.position=1;
            break;
        case GLUT_KEY_UP:
            status.position=0;
            break;
        }
    else if(status.modus==MODUS_START)
        switch(key)
        {
        case GLUT_KEY_LEFT:
            status.position--;
            status.ugao=0;
            break;
        case GLUT_KEY_RIGHT:
            status.position++;
            status.ugao=0;
            break;
        }

    if(status.paused==true)
        switch(key)
        {
        case GLUT_KEY_DOWN:
            status.position=1;
            break;
        case GLUT_KEY_UP:
            status.position=0;
            break;
        }

    switch(key)
    {
    case GLUT_KEY_F11:
        glutcpp::fullScreenToggle();
        break;
    }

}


/* skidanje flagova za specijalne karaktere koja su stisnuta na tastaturi */
void SpecialKeyListener::keyUp(int key, int x, int y) const
{
    x=x;y=y;
    if(status.modus==MODUS_ARENA)
        for(Robot * item : roboti)
            if(item->getPlayer()==PLAYER_2)
                item->unset_key(key);
}
