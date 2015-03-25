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


#ifndef ROBOT_H
#define ROBOT_H


#include "tacka.h"


#define KEY_NONE 0
#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_LEFT 3
#define KEY_RIGHT 4


#define PLAYER_NONE 0
#define PLAYER_1 1
#define PLAYER_2 2
#define PLAYER_TEST 3


class Robot
{
public:
    Robot(int player=PLAYER_NONE,Tacka t=Tacka(0,0,0));

    void set_key(unsigned char key);
    void unset_key(unsigned char key);
    void set_key(int key);
    void unset_key(int key);
    virtual void animation();
    virtual void draw();
    void display3D(int ugao,int width,int height,int arg1,int arg2,int light_status);
    Tacka getPos() const { return _center; }
    float getUgao() const { return _ugao; }
    
protected:

    int _player;
    unsigned char _up_down;
    unsigned char _left_right;
    Tacka _center;
    float _ugao;
    float _speed=5;
    int _ability_1=0;
    int _ability_2=0;
    int _ability_3=0;
    int _ability_4=0;
    int _ugao_rotacije; // sta je bre ovo? - Banjac
};

#endif // ROBOT_H
