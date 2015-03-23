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


#include "robot.h"
#include "glut.h"


Robot::Robot(int player,Tacka t)
    : _player(player) , _center(t)
{}

void Robot::set_key(unsigned char key)
{
    if(this->_player==PLAYER_1)
        switch(key)
        {
            case 'a':
            case 'A':
                this->left_right=KEY_LEFT;
                break;
            case 'w':
            case 'W':
                this->up_down=KEY_UP;
                break;
            case 's':
            case 'S':
                this->up_down=KEY_DOWN;
                break;
            case 'd':
            case 'D':
                this->left_right=KEY_RIGHT;
                break;
        }
    else if(this->_player==PLAYER_2)
        switch(key)
        {
            case 'h':
            case 'H':
                this->left_right=KEY_LEFT;
                break;
            case 'u':
            case 'U':
                this->up_down=KEY_UP;
                break;
            case 'j':
            case 'J':
                this->up_down=KEY_DOWN;
                break;
            case 'k':
            case 'K':
                this->left_right=KEY_RIGHT;
                break;
        }
}


void Robot::unset_key(unsigned char key)
{
    if(this->_player==PLAYER_1)
        switch(key)
        {
            case 'a':
            case 'A':
                if(this->left_right==KEY_LEFT)
                    this->left_right=KEY_NONE;
                break;
            case 'w':
            case 'W':
                if(this->up_down==KEY_UP)
                    this->up_down=KEY_NONE;
                break;
            case 's':
            case 'S':
                if(this->up_down==KEY_DOWN)
                    this->up_down=KEY_NONE;
                break;
            case 'd':
            case 'D':
                if(this->left_right==KEY_RIGHT)
                    this->left_right=KEY_NONE;
                break;
        }
    else if(this->_player==PLAYER_2)
        switch(key)
        {
            case 'h':
            case 'H':
                if(this->left_right==KEY_LEFT)
                    this->left_right=KEY_NONE;
                break;
            case 'u':
            case 'U':
                if(this->up_down==KEY_UP)
                    this->up_down=KEY_NONE;
                break;
            case 'j':
            case 'J':
                if(this->up_down==KEY_DOWN)
                    this->up_down=KEY_NONE;
                break;
            case 'k':
            case 'K':
                if(this->left_right==KEY_RIGHT)
                    this->left_right=KEY_NONE;
                break;
        }
}



void Robot::animation()
{
    if(this->left_right==KEY_LEFT)
        this->_center.add(-1,0,0);
    else if(this->left_right==KEY_RIGHT)
        this->_center.add(1,0,0);

    if(this->up_down==KEY_UP)
        this->_center.add(0,0,-1);
    else if(this->up_down==KEY_DOWN)
        this->_center.add(0,0,1);

}


void Robot::draw()
{
    glut::color(1,1,1,1);
    glut::push();
        glut::translate(this->_center);
        glut::translate(0,10,0);
        glut::cube(20);
    glut::pop();
}
