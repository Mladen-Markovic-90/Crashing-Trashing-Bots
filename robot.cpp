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
#include "robot.h"
#include "glutcpp/glutcpp.h"
#include "provera.h"
#include <cmath>
#include "glutcpp/glutAnimationTimer.h"


/* Konstruktor za Robot koji prima argument, za koji igrac se vezuje i gde se nalazi inicijalno u prostoru */
Robot::Robot(float ticksPerSecond, int player, Tacka center, Tacka front, float ugao,
             int cooldown1, int cooldown2, int cooldown3, int cooldown4,
             Tacka northWest, Tacka northEast, Tacka southEast, Tacka southWest, float radius)
    : _ticksPerSecond(ticksPerSecond),_player(player) , _center(center) , _front(front), _ugao(ugao),
      _ability_1_cooldown(cooldown1) , _ability_2_cooldown(cooldown2) ,
      _ability_3_cooldown(cooldown3) , _ability_4_cooldown(cooldown4) ,
      _northWest(northWest), _northEast(northEast) , _southEast(southEast), _southWest(southWest), _radius(radius)
    {
    _speed=100/_ticksPerSecond;
    _povrsina+=provera::povrsina(northWest,northEast,Tacka(0,0,0));
    _povrsina+=provera::povrsina(northEast,southEast,Tacka(0,0,0));
    _povrsina+=provera::povrsina(southEast,southWest,Tacka(0,0,0));
    _povrsina+=provera::povrsina(southWest,northWest,Tacka(0,0,0));
    std::cout << "Povrsina je: " << _povrsina << std::endl;
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
            if(this->_ability_1<=0)
                this->_ability_1=this->_ability_1_cooldown;
            break;
        case '2':
            if(this->_ability_2<=0 && this->_energy >= 20)
            {
                this->_ability_2=this->_ability_2_cooldown;
                this->_energy-=20;
            }
            break;
        case '3':
            if(this->_ability_3<=0 && this->_energy >= 50)
            {
                this->_ability_3=this->_ability_3_cooldown;
                this->_energy-=50;
            }
            break;
        case '4':
            if(this->_ability_4<=0 && this->_energy == 100)
            {
                this->_ability_4=this->_ability_4_cooldown;
                this->_energy=0;
            }
            break;
        }

    else if(this->_player==PLAYER_2)
        switch(key)
        {

        /* ispitivanje i iskoriscavanje ability za player 2 */
        case '7':
            if(this->_ability_1<=0)
                this->_ability_1=this->_ability_1_cooldown;
            break;
        case '8':
            if(this->_ability_2<=0 && this->_energy >= 20)
            {
                this->_ability_2=this->_ability_2_cooldown;
                this->_energy-=20;
            }
            break;
        case '9':
            if(this->_ability_3<=0 && this->_energy >= 50)
            {
                this->_ability_3=this->_ability_3_cooldown;
                this->_energy-=50;
            }
            break;
        case '0':
            if(this->_ability_4<=0 && this->_energy == 100)
            {
                this->_ability_4=this->_ability_4_cooldown;
                this->_energy=0;
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


/* Animacija i izracunavanje za robot, izvrsava se u klasi animationTimer */
void Robot::animation()
{
    /* regeneracija energy */
    this->_energy+=5.0/_ticksPerSecond;
    if(this->_energy > 100)
        this->_energy=100;

    /* cooldown za abilitys, ako je iskoriscen */
    if(this->_ability_1>0)
        this->_ability_1--;
    if(this->_ability_2>0)
        this->_ability_2--;
    if(this->_ability_3>0)
        this->_ability_3--;
    if(this->_ability_4>0)
        this->_ability_4--;

    /* pravilno kretanje robotica napred i nazad pod uglom */
    if( (this->_left_right==KEY_LEFT && this->_up_down==KEY_UP)
	|| (this->_left_right==KEY_RIGHT && this->_up_down==KEY_DOWN) )
        this->_ugao-=5;
    else if( (this->_left_right==KEY_RIGHT && this->_up_down==KEY_UP) 
	|| (this->_left_right==KEY_LEFT && this->_up_down==KEY_DOWN) )
        this->_ugao+=5;

    /* azuriramo centar tako da bude tacan u svakom trenutku bez zavisnosti od gluta */
    if(this->_up_down==KEY_UP)
        this->_center.add(this->_speed*std::sin(this->_ugao/180*M_PI),0,-this->_speed*std::cos(this->_ugao/180*M_PI));
    else if(this->_up_down==KEY_DOWN)
        this->_center.add(-this->_speed*std::sin(this->_ugao/180*M_PI),0,this->_speed*std::cos(this->_ugao/180*M_PI));
}


/* Iscrtavanje robotera, izvrsava se u klasi display */
void Robot::draw()
{
    glutcpp::color(1,1,1,1);
    glutcpp::push();
        glutcpp::translate(this->_center);
        glutcpp::translate(0,10,0);
        glutcpp::rotate(-this->_ugao,0,1,0);
        glutcpp::cube(20);
    glutcpp::pop();
}


/* Iscrtavanje podataka na povrsinu prozora, izvrsava se u klasi display */
void Robot::display3D(int ugao,int width,int height,int arg1,int arg2)
{
    /* crtanje display status za player 1 */
    if(this->_player==PLAYER_1)
    {
        glutcpp::light(GL_OFF);
        glutcpp::screenDisplayBegin3D();

        float number=1.0-this->_ability_1/(float)this->_ability_1_cooldown;
        glutcpp::color(1,number,number,1);
        glutcpp::text(-0.9,-0.95,"1");

        number=1.0-this->_ability_2/(float)this->_ability_2_cooldown;
        glutcpp::color(1,number,number,1);
        glutcpp::text(-0.8,-0.95,"2");

        number=1.0-this->_ability_3/(float)this->_ability_3_cooldown;
        glutcpp::color(1,number,number,1);
        glutcpp::text(-0.7,-0.95,"3");

        number=1.0-this->_ability_4/(float)this->_ability_4_cooldown;
        glutcpp::color(1,number,number,1);
        glutcpp::text(-0.6,-0.95,"4");

        number=this->_health/100.0;

        if(this->_health < 100)
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

        float number=1.0-this->_ability_1/(float)this->_ability_1_cooldown;
        glutcpp::color(1,number,number,1);
        glutcpp::text(0.6,-0.95,"7");

        number=1.0-this->_ability_2/(float)this->_ability_2_cooldown;
        glutcpp::color(1,number,number,1);
        glutcpp::text(0.7,-0.95,"8");

        number=1.0-this->_ability_3/(float)this->_ability_3_cooldown;
        glutcpp::color(1,number,number,1);
        glutcpp::text(0.8,-0.95,"9");

        number=1.0-this->_ability_4/(float)this->_ability_4_cooldown;
        glutcpp::color(1,number,number,1);
        glutcpp::text(0.9,-0.95,"0");

        number=this->_health/100.0;

        if(this->_health < 100)
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
