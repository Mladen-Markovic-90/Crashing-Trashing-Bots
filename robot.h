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
#include "robot.h"
#include "abilitys/ability.h"
#include <cmath>
#include <vector>
#include "telo.h"
#include "prepreka.h"
#include "glutcpp/tacka.h"

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
using namespace std;

/* nadklasa za robotice i rad sa njim */
class Robot : public Telo
{
public:
    /* Konstruktor za Robot koji prima argument, za koji igrac se vezuje i gde se nalazi inicijalno u prostoru */
    Robot(float ticksPerSecond,int player,Tacka centar,Tacka front,float ugao,
          int cooldown1,int cooldown2,int cooldown3,int cooldown4,
          Tacka northWest,Tacka northEast,Tacka southEast ,Tacka southWest, float radius);

    /* Dekonstruktor */
    ~Robot();

    /* Funkcija za postavljanje flags za obicne karaktere, izvrsava se u klasi keys */
    void set_key(unsigned char key);

    void impulse (const Tacka &i);
    /* Funkcija za skidanje flags za obicne karaktere, izvrsava se u klasi keys */
    void unset_key(unsigned char key);

    /* Funkcija za postavljanje flags za specijalne karaktere, izvrsava se u klasi special_keys */
    void set_key(int key);

    /* Funkcija za skidanje flags za specijalne karaktere, izvrsava se u klasi special_keys */
    void unset_key(int key);

    /* Animacija i izracunavanje za robotic, izvrsava se u klasi timer */
    virtual void animation(const vector<Robot*> &, const vector<Prepreka *> &prepreke);

    /* Iscrtavanje robotica, izvrsava se u klasi display */
    virtual void draw() {}

    void hit(int damage,bool flag);

    /* Iscrtavanje podataka na povrsinu prozora, izvrsava se u klasi display */
    void display3D(int ugao,int width,int height,int arg1,int arg2);

    /* Getter za player vezan za robotica */
    int getPlayer() const { return _player; }

    /* geteri za brzinu i silu */
    Tacka vgetSpeed() const { return _speed; }
    float getSpeed() const { return _speed.norm(); }
    Tacka vgetForce() const { return _force; }
    float getForce() const { return _force.norm(); }

    float getMass() const {return _mass; }
    
    void kolizijaAbility(const vector<Robot*> &roboti, const vector<Prepreka*> &prepreke);

protected:
    /* Flagovi za pravce koji su stisnuti */
    unsigned char _up_down=KEY_NONE;
    unsigned char _left_right=KEY_NONE;

    /* broj prikaza po sekundi */
    float _ticksPerSecond;

    /* Flag koji oznacava igraca */
    int _player;

    /* Front (prednji deo) robota */
    Tacka _front;

    /* Privremena promenljiva za brzinu */
    Tacka _speed;
    //float _acceleration;
    Tacka _force;
    float _mass;
    float _friction; // ovo je glupost

    Ability * _ability01;
    Ability * _ability02;
    //Ability test=Ability(5,100,5,Tacka(0,0,0));

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

    /* promenljive za energy/health */
    float _energy=100;
    float _health=100;

    
};


#include "robot.cpp"


#endif // ROBOT_H
