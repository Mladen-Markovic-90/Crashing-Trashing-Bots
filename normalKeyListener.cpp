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
#include "glutcpp/glutReshapeListener.h"
#include "robot.h"
#include "robot_1.h"
#include "robot_2.h"
#include "robot_3.h"

/* postavljanje flagova ili radnja za karaktere koja su stisnuta na tastaturi */
void normalKeyListener::keyDown(unsigned char normalKey, int x, int y) const
{
    x=x;y=y;
    if(normalKey==27 || normalKey==' ')
        if(status.paused==false)
            status.paused=true;
    if(status.modus==MODUS_ARENA || status.modus==MODUS_TEST_MLADEN)
    {
        if(status.paused==false)
            for(Robot * item : roboti)
                if(item->getPlayer()!=PLAYER_NONE)
                    item->set_key(normalKey);
    }
    else if(status.modus==MODUS_MENI)
    {
        switch(normalKey)
        {
            /* ENTER */
            case '\n':
            case '\r':
                if(status.position==0)
                {
                    status.modus=MODUS_START;
                    status.position=999;
                    status.flag=PLAYER_1;
		    
                    for (vector<Robot *>::iterator it = roboti.begin(); it != roboti.end(); ++it)
			delete *it;
		    roboti.clear();
		    
                    glutReshapeListenerInit::getReshapeListener()->reshape();
                }
                else if(status.position==1)
                    exit(EXIT_SUCCESS);
                break;
        }
    }
    else if(status.modus==MODUS_START)
        switch(normalKey)
        {
            /* ENTER */
            case '\n':
            case '\r':
                int player;
                if(status.flag==PLAYER_1)
                    player=PLAYER_1;
                else
                    player=PLAYER_2;
                float ticksPerSecond=glutAnimationTimerInit::getAnimationTimer()->getTicksPerSecond();
                int number=status.flag-PLAYER_1;
                if(status.position%3==0)
                    roboti.push_back(new Robot_1(ticksPerSecond,player,Tacka(-100+200*number,0,0)));
                else if(status.position%3==1)
                    roboti.push_back(new Robot_2(ticksPerSecond,player,Tacka(-100+200*number,0,0)));
                else if(status.position%3==2)
                    roboti.push_back(new Robot_3(ticksPerSecond,player,Tacka(-100+200*number,0,0)));
                status.position=999;
                status.ugao=0;
                if(status.flag==PLAYER_2)
                {
                    status.flag=0;
                    status.position=0;
                    status.paused=false;
                    status.modus=MODUS_ARENA;
                    glutReshapeListenerInit::getReshapeListener()->reshape();
                }
                status.flag++;
                break;
        }

    if(status.modus==MODUS_ARENA || status.modus==MODUS_TEST_MLADEN)
        if(status.paused==true)
            switch(normalKey)
            {
            /* ENTER */
            case '\n':
            case '\r':
                if(status.position==0)
                    status.paused=false;
                else if(status.position==1)
                {
                    status.position=0;
		    for (Robot * it : roboti) {
			
		    }
			
                    status.modus=MODUS_MENI;
                    glutReshapeListenerInit::getReshapeListener()->reshape();
                }
                break;
            }
}


/* skidanje flagova za karaktere koja su stisnuta na tastaturi */
void normalKeyListener::keyUp(unsigned char normalKey, int x, int y) const
{
    x=x;y=y;
    if(status.modus==MODUS_ARENA || status.modus==MODUS_TEST_MLADEN)
    {
        for(Robot * item : roboti)
            if(item->getPlayer()!=PLAYER_NONE)
                item->unset_key(normalKey);
    }

}
