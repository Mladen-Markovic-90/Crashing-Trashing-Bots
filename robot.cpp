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


/* Nadklasa za robotice i rad sa njim */


/* Ukljucivanje potrebnih zaglavlja */
#include "global.h"
#include "telo.h"
#include "robot.h"
#include "glutcpp/glutcpp.h"
#include "provera.h"
#include <cmath>
#include <vector>
#include "glutcpp/glutAnimationTimer.h"
#include "abilitys/ability.h"
#include "glutcpp/tacka.h"

using namespace std;
/* Konstruktor za Robot koji prima argument, za koji igrac se vezuje i gde se nalazi inicijalno u prostoru */
Robot::Robot(float ticksPerSecond,int player,Tacka centar,Tacka front,float ugao,int cooldown3,
             Tacka northWest,Tacka northEast,Tacka southEast ,Tacka southWest, float radius, float health)
    : Telo(northWest, northEast, southEast, southWest, radius, centar, ugao)
{
    _player=player;
    _front=front;
    _ability_3_cooldown=cooldown3;
    _ticksPerSecond=ticksPerSecond;

    _speed = Tacka(0,0,0);
    //_acceleration = 0;
    //_mass = 50; // privremeno
    _force = Tacka(0,0,0);
    _friction = 0;

    _health=health;
    _max_health=health;
}


Robot::~Robot()
{
    delete _ability01;
    delete _ability02;
}


/* Funkcija za postavljanje flags za obicne karaktere, izvrsava se u klasi keys */
void Robot::set_key(unsigned char key)
{
    if(this->_player==PLAYER_1)
        switch(key)
            {
                /* kretanje robotica za player 1 */
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

                /* ispitivanje i iskoriscavanje ability za player 1 */
            case '1':
                _ability01->use();
                break;
            case '2':
                if(this->_energy >= 20)
                    if(_ability02->use())
                        this->_energy-=20;
                break;
            case '3':
                if(this->_ability_3<=0 && this->_energy >= 50)
                    {
                        this->_ability_3=this->_ability_3_cooldown;
                        this->_energy-=50;
                        _reduction=1;
                    }
                break;
            }

    else if(this->_player==PLAYER_2)
        switch(key)
            {

                /* ispitivanje i iskoriscavanje ability za player 2 */
            case '7':
                _ability01->use();
                break;
            case '8':
                if(this->_energy >= 20)
                    if(_ability02->use())
                        this->_energy-=20;
                break;
            case '9':
                if(this->_ability_3<=0 && this->_energy >= 50)
                    {
                        this->_ability_3=this->_ability_3_cooldown;
                        this->_energy-=50;
                        _reduction=1;
                    }
                break;
            }
}


/* Funkcija za postavljanje flags za specijalne karaktere, izvrsava se u klasi specialKeyListener */
void Robot::set_key(int key)
{
    if(this->_player==PLAYER_2)
        switch(key)
            {

                /* kretanje robotica za player 2 */
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


/* Funkcija za skidanje flags za obicne karaktere, izvrsava se u klasi normalKeyListener */
void Robot::unset_key(unsigned char key)
{
    if(this->_player==PLAYER_1)
        switch(key)
            {
                /* kretanje robotica za player 1 */
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
}


/* Funkcija za skidanje flags za specijalne karaktere, izvrsava se u klasi specialKeyListener */
void Robot::unset_key(int key)
{
    if(this->_player==PLAYER_2)
        switch(key)
        {
        /* kretanje robotica za player 2 */
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

int Robot::getHealth()
{
    return _health;
}

/* Animacija i izracunavanje za robot, izvrsava se u klasi animationTimer */
void Robot::animation(const vector<Robot*> &roboti, const vector<Prepreka*> &prepreke)
{
    if(_health <= 0)
        return;

    /* regeneracija energy */
    this->_energy+=5.0/_ticksPerSecond;
    if(this->_energy > 100)
        this->_energy=100;

    if(this->_ability_3>0)
        this->_ability_3--;

    _reduction=(float)_ability_3/_ability_3_cooldown;

    float ugao_old=this->_ugao;
    /* skretanja */

    Tacka unapred = provera::position(_front, _center, _ugao) - _center;
    double cosugla = Vektor3D::cos_fi(unapred, _speed);

    if((_left_right==KEY_LEFT && cosugla > 0) ||
       (_left_right==KEY_RIGHT && cosugla <= 0)) {
	this->_ugao-=getSpeed();
	_speed = Vektor3D::rotate2D(_speed, -getSpeed() * M_PI / 180);
    }
    else if((_left_right==KEY_RIGHT && cosugla > 0) ||
	    (_left_right==KEY_LEFT && cosugla <= 0)) {

	this->_ugao+=getSpeed();
	_speed = Vektor3D::rotate2D(_speed, getSpeed() * M_PI / 180);
    }
    //std::cout << _center.get_x() <<" "<< _center.get_y() <<" "<< _center.get_z() << endl;
    //std::cout << _front.get_x() <<" "<< _front.get_y() <<" "<< _front.get_z() << endl;
    /* azuriramo centar tako da bude tacan u svakom trenutku bez zavisnosti od gluta */
    Tacka pomeraj(0,0,0);
    double koef = 1.0;

    switch (this->_up_down) {
	//pogon
    case KEY_UP:
	_force = 30 * Vektor3D::rotate2D(Tacka(0,0,-1), _ugao * M_PI / 180);
	break;
    case KEY_DOWN:
	_force = -30 * Vektor3D::rotate2D(Tacka(0,0,-1), _ugao * M_PI / 180);
	break;
    case KEY_NONE:
	_force = Tacka(0,0,0);
	break;
    }

    //_acceleration = _force / _mass;
    
    if ( (getSpeed() > 0.5 || getSpeed() < -0.5)) {
	_speed -= (vgetSpeed() / fabs(vgetSpeed().norm())) * 0.4;
    }
    
    //ogranicenje brzine
    // TODO: OVO NE TREBA DA BUDU MAGICNE KONSTANTE
    if (getSpeed() < 10) {
	    _speed += (vgetForce() / _mass);
    }
    //cout << "aasoduduf " << _speed << endl;
    if (getSpeed() >= -0.5 && getSpeed() <= 0.5 && getForce() == 0) {
	_speed = Tacka(0,0,0);
    }
    
    //    pomeraj = Tacka(this->_speed*std::sin(this->_ugao/180*M_PI),0,-this->_speed*std::cos(this->_ugao/180*M_PI));
    pomeraj = _speed;  //?
    for (Robot *it : roboti) {
        if (it == this)
            continue;
        double n_koef;

	//  kolizija
        if ((n_koef = pretraga(*it, pomeraj, 0.0, 1.0, 0)) < koef) {
            koef = n_koef;

	    it->impulse((_speed+it->_speed) * _mass);

	    this->impulse(it->_mass * ( _speed + it->_speed));
	    
	    _speed = Tacka(0,0,0);
	    //_acceleration = 0;// za sad
	}
    }

    for (Prepreka *it : prepreke) {
        double n_koef;
        if ((n_koef = pretraga(*it, pomeraj, 0.0, 1.0, 0)) < koef) {
            koef = n_koef;
            _speed = Tacka(0,0,0);
	    //_acceleration = 0;// za sad
        }
    }

    this->_center.add(pomeraj * koef);

    if(koef < 0.01)
        this->_ugao=ugao_old;


    /* cooldown za abilitys, ako je iskoriscen */
    _ability01->animation(_center,_ugao);
    _ability02->animation(_center,_ugao);

    kolizijaAbility(roboti,prepreke);
}


void Robot::kolizijaAbility(const vector<Robot*> &roboti, const vector<Prepreka*> &prepreke)
{
    for(Prepreka * item : prepreke)
    {
        _ability01->kolizija(*item);
        _ability02->kolizija(*item);
    }


    for(Robot * item : roboti)
        if(item!=this)
        {
            item->hit(_ability01->getDamage(),_ability01->kolizija(*item));
            item->hit(_ability02->getDamage(),_ability02->kolizija(*item));
        }
}


void Robot::hit(int damage,bool flag)
{
    if(flag==true)
        _health=_health-damage*(1.0-_reduction);
    if(_health<0)
        _health=0;
}


/* Iscrtavanje podataka na povrsinu prozora, izvrsava se u klasi display */
void Robot::display3D(int ugao,int width,int height,int arg1,int arg2)
{

    /* crtanje display status za player 1 */
    if(this->_player==PLAYER_1)
    {
        glutcpp::light(GL_OFF);
        glutcpp::screenDisplayBegin3D();

        //float number=1.0-this->_ability_1/(float)this->_ability_1_cooldown;
        float number=1.0-_ability01->getTime()/(float)_ability01->getCooldown();
        glutcpp::color(1,number,number,1);
        glutcpp::text(-0.9,-0.95,"1");

        //number=1.0-this->_ability_2/(float)this->_ability_2_cooldown;
        number=1.0-_ability02->getTime()/(float)_ability02->getCooldown();
        glutcpp::color(1,number,number,1);
        glutcpp::text(-0.8,-0.95,"2");

        number=1.0-this->_ability_3/(float)this->_ability_3_cooldown;
        glutcpp::color(1,number,number,1);
        glutcpp::text(-0.7,-0.95,"3");

        number=this->_health/_max_health;

        if(this->_health < _max_health)
            glutcpp::color(1,0,0,1);
        else
            glutcpp::color(1,0,0,0.7);
        glutcpp::pravougaonik(Tacka(-0.9,0.9,0),Tacka(-0.9,0.95,0),Tacka(-0.9+0.5*number,0.95,0),Tacka(-0.9+0.5*number,0.9,0));

        glutcpp::color(0,0,0,0.7);
        for(int i=0;i<=9;i++)
            glutcpp::linija(Tacka(-0.9+0.05*i,0.9,0),Tacka(-0.9+0.05*i,0.92,0));

        number=this->_energy/100.0;

        if(this->_energy < 100)
            glutcpp::color(0.5,0.5,1,1);
        else
            glutcpp::color(0.5,0.5,1,0.7);
        glutcpp::pravougaonik(Tacka(-0.9,0.8,0),Tacka(-0.9,0.85,0),Tacka(-0.9+0.5*number,0.85,0),Tacka(-0.9+0.5*number,0.8,0));

        glutcpp::color(0,0,0,0.7);
        for(int i=0;i<=9;i++)
            glutcpp::linija(Tacka(-0.9+0.05*i,0.8,0),Tacka(-0.9+0.05*i,0.82,0));

        glutcpp::screenDisplayEnd3D(ugao,width,height,arg1,arg2);

        glutcpp::light(GL_ON);
    }

    /* crtanje display status za player 2 */
    else if(this->_player==PLAYER_2)
    {
        glutcpp::light(GL_OFF);
        glutcpp::screenDisplayBegin3D();

        float number=1.0-_ability01->getTime()/(float)_ability01->getCooldown();
        glutcpp::color(1,number,number,1);
        glutcpp::text(0.6,-0.95,"7");

        number=1.0-_ability02->getTime()/(float)_ability02->getCooldown();
        glutcpp::color(1,number,number,1);
        glutcpp::text(0.7,-0.95,"8");

        number=1.0-this->_ability_3/(float)this->_ability_3_cooldown;
        glutcpp::color(1,number,number,1);
        glutcpp::text(0.8,-0.95,"9");

        number=this->_health/_max_health;

        if(this->_health < _max_health)
            glutcpp::color(1,0,0,1);
        else
            glutcpp::color(1,0,0,0.7);
        glutcpp::pravougaonik(Tacka(0.9,0.9,0),Tacka(0.9,0.95,0),Tacka(0.9-0.5*number,0.95,0),Tacka(0.9-0.5*number,0.9,0));

        glutcpp::color(0,0,0,0.7);
        for(int i=0;i<=9;i++)
            glutcpp::linija(Tacka(0.9-0.05*i,0.9,0),Tacka(0.9-0.05*i,0.92,0));

        number=this->_energy/100.0;

        if(this->_energy < 100)
            glutcpp::color(0.5,0.5,1,1);
        else
            glutcpp::color(0.5,0.5,1,0.7);
        glutcpp::pravougaonik(Tacka(0.9,0.8,0),Tacka(0.9,0.85,0),Tacka(0.9-0.5*number,0.85,0),Tacka(0.9-0.5*number,0.8,0));

        glutcpp::color(0,0,0,0.7);
        for(int i=0;i<=9;i++)
            glutcpp::linija(Tacka(0.9-0.05*i,0.8,0),Tacka(0.9-0.05*i,0.82,0));

        glutcpp::screenDisplayEnd3D(ugao,width,height,arg1,arg2);
        glutcpp::light(GL_ON);
    }
}

void Robot::impulse (const Tacka &i)
{
    _speed += i / _mass;
    _force += i / _mass;
}

// void Robot::angularImpulse()
// {
    
// }
