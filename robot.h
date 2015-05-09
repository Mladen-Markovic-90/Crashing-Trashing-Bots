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


/* Ukljucivanje potrebnih zaglavlja */
#include "global.h"
#include <cmath>


/* Definicije konstanti za dugmad */
#define KEY_NONE 0
#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_LEFT 3
#define KEY_RIGHT 4


/* Definicije konstanti za player */
#define PLAYER_NONE 0
#define PLAYER_1 1
#define PLAYER_2 2


/* nadklasa za robotice i rad sa njim */
class Robot
{
public:
    /* Konstruktor za Robot koji prima argument, za koji igrac se vezuje i gde se nalazi inicijalno u prostoru */
    Robot(float ticksPerSecond,int player,Tacka centar,Tacka front,float ugao,
          int cooldown1,int cooldown2,int cooldown3,int cooldown4,
          Tacka northWest,Tacka northEast,Tacka southEast ,Tacka southWest, float radius);

    /* Funkcija za postavljanje flags za obicne karaktere, izvrsava se u klasi keys */
    void set_key(unsigned char key);

    /* Funkcija za skidanje flags za obicne karaktere, izvrsava se u klasi keys */
    void unset_key(unsigned char key);

    /* Funkcija za postavljanje flags za specijalne karaktere, izvrsava se u klasi special_keys */
    void set_key(int key);

    /* Funkcija za skidanje flags za specijalne karaktere, izvrsava se u klasi special_keys */
    void unset_key(int key);

    /* Animacija i izracunavanje za robotic, izvrsava se u klasi timer */
    virtual void animation();

    /* Iscrtavanje robotica, izvrsava se u klasi display */
    virtual void draw();

    /* Iscrtavanje podataka na povrsinu prozora, izvrsava se u klasi display */
    void display3D(int ugao,int width,int height,int arg1,int arg2);


    //TODO: PODESITI OSTALE PARAMETRE KASNIJE KADA BUDU NAPRAVLJENI
    void setUgao(float ugao) {_ugao=ugao;}
    void setPos(Tacka t) {_center=t;}
    //END TODO


    /* Getter za centar robotica */
    Tacka getPos() const { return _center; }

    /* Getter za ugao koji sluzi za rotaciju robotica */
    float getUgao() const { return _ugao; }

    /* Getter za player vezan za robotica */
    int getPlayer() const { return _player; }

    double getPovrsina() const { return _povrsina; }

    /* Getter za front tacku */
    Tacka getFront() const {
        Tacka tmp=Tacka(0,0,0);
        tmp.set_x(_front.get_x()*std::cos(-_ugao/180.0*M_PI)+_front.get_z()*std::sin(-_ugao/180.0*M_PI));
        tmp.set_z(_front.get_x()*std::sin(-_ugao/180.0*M_PI)+_front.get_z()*std::cos(-_ugao/180.0*M_PI));
        tmp.add(_center);
        return tmp;
    }
    
protected:
    float _ticksPerSecond;

    /* Flag koji oznacava igraca */
    int _player;

    /* Flagovi za pravce koji su stisnuti */
    unsigned char _up_down;
    unsigned char _left_right;

    /* Centar robota */
    Tacka _center;

    /* Front (prednji deo) robota */
    Tacka _front;

    /* Ugao koji sluzi za rotaciju robotica */
    float _ugao;

    /* Privremena promenljiva za brzinu */
    float _speed;

    /* Promenljive/Flag za stanje abilitys */
    int _ability_1=0;
    int _ability_2=0;
    int _ability_3=0;
    int _ability_4=0;

    /* Promenljive koje oznacavaju cooldown od abilitys */
    int _ability_1_cooldown;
    int _ability_2_cooldown;
    int _ability_3_cooldown;
    int _ability_4_cooldown;

    float _energy=100;
    float _health=100;

    Tacka _northWest;
    Tacka _northEast;
    Tacka _southEast;
    Tacka _southWest;
    float _radius;

    double _povrsina=0;
};


#include "robot.cpp"


#endif // ROBOT_H
