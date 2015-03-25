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


#include "global.h"
#include "robot.h"
#include "glut.h"
#include <cmath>


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
            this->_left_right=KEY_LEFT;
            break;
        case 'w':
        case 'W':
            this->_up_down=KEY_UP;
            break;
        case 's':
        case 'S':
            this->_up_down=KEY_DOWN;
            break;
        case 'd':
        case 'D':
            this->_left_right=KEY_RIGHT;
            break;
        case '1':
            if(this->_ability_1==0)
                this->_ability_1=100;
            break;
        }
    else if(this->_player==PLAYER_2)
        switch(key)
        {
        case 'h':
        case 'H':
            this->_left_right=KEY_LEFT;
            break;
        case 'u':
        case 'U':
            this->_up_down=KEY_UP;
            break;
        case 'j':
        case 'J':
            this->_up_down=KEY_DOWN;
            break;
        case 'k':
        case 'K':
            this->_left_right=KEY_RIGHT;
            break;
        }
}



void Robot::set_key(int key)
{
    if(this->_player==PLAYER_TEST)
        switch(key)
        {
        case GLUT_KEY_LEFT:
            this->_left_right=KEY_LEFT;
            break;
        case GLUT_KEY_UP:
            this->_up_down=KEY_UP;
            break;
        case GLUT_KEY_DOWN:
            this->_up_down=KEY_DOWN;
            break;
        case GLUT_KEY_RIGHT:
            this->_left_right=KEY_RIGHT;
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
            if(this->_left_right==KEY_LEFT)
                this->_left_right=KEY_NONE;
            break;
        case 'w':
        case 'W':
            if(this->_up_down==KEY_UP)
                this->_up_down=KEY_NONE;
            break;
        case 's':
        case 'S':
            if(this->_up_down==KEY_DOWN)
                this->_up_down=KEY_NONE;
            break;
        case 'd':
        case 'D':
            if(this->_left_right==KEY_RIGHT)
                this->_left_right=KEY_NONE;
            break;
        }
    else if(this->_player==PLAYER_2)
        switch(key)
        {
        case 'h':
        case 'H':
            if(this->_left_right==KEY_LEFT)
                this->_left_right=KEY_NONE;
            break;
        case 'u':
        case 'U':
            if(this->_up_down==KEY_UP)
                this->_up_down=KEY_NONE;
            break;
        case 'j':
        case 'J':
            if(this->_up_down==KEY_DOWN)
                this->_up_down=KEY_NONE;
            break;
        case 'k':
        case 'K':
            if(this->_left_right==KEY_RIGHT)
                this->_left_right=KEY_NONE;
            break;
        }
}



void Robot::unset_key(int key)
{
    if(this->_player==PLAYER_TEST)
        switch(key)
        {
        case GLUT_KEY_LEFT:
            if(this->_left_right==KEY_LEFT)
                this->_left_right=KEY_NONE;
            break;
        case GLUT_KEY_UP:
            if(this->_up_down==KEY_UP)
                this->_up_down=KEY_NONE;
            break;
        case GLUT_KEY_DOWN:
            if(this->_up_down==KEY_DOWN)
                this->_up_down=KEY_NONE;
            break;
        case GLUT_KEY_RIGHT:
            if(this->_left_right==KEY_RIGHT)
                this->_left_right=KEY_NONE;
            break;
        }

}


void Robot::animation()
{
    if(this->_ability_1>0)
        this->_ability_1--;
    if( (this->_left_right==KEY_LEFT && this->_up_down==KEY_UP)
	|| (this->_left_right==KEY_RIGHT && this->_up_down==KEY_DOWN) )
        this->_ugao-=5;
    else if( (this->_left_right==KEY_RIGHT && this->_up_down==KEY_UP) 
	|| (this->_left_right==KEY_LEFT && this->_up_down==KEY_DOWN) )
        this->_ugao+=5;

    if(this->_up_down==KEY_UP)
        this->_center.add(this->_speed*std::sin(this->_ugao/180*M_PI),0,-this->_speed*std::cos(this->_ugao/180*M_PI));
    else if(this->_up_down==KEY_DOWN)
        this->_center.add(-this->_speed*std::sin(this->_ugao/180*M_PI),0,this->_speed*std::cos(this->_ugao/180*M_PI));

}


void Robot::draw()
{
    glut::color(1,1,1,1);
    glut::push();
        glut::translate(this->_center);
        glut::translate(0,10,0);
        glut::rotate(-this->_ugao,0,1,0);
        glut::cube(20);
    glut::pop();
}


void Robot::display3D(int ugao,int width,int height,int arg1,int arg2,int light_status)
{

    glut::light(GL_OFF);
    glut::screenDisplayBegin3D();

    float number1=1.0-this->_ability_1/100.0;

    glut::color(1,number1,number1,0);

    glut::text(-0.9,-0.9,"1");

    glut::screenDisplayEnd3D(ugao,width,height,arg1,arg2);
    glut::light(light_status);
}
