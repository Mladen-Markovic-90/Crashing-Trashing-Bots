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


/* Klasa za robotic 3 i rad sa njim */


/* Ukljucivanje potrebnih zaglavlja */
#include "glutcpp/glutcpp.h"
#include <cmath>
#include <iostream>
#include "abilitys/ability.h"
#include "abilitys/robot3_ability1.h"
#include "abilitys/robot3_ability2.h"
#include "robot.h"
#include "robot_3.h"


/* Konstruktor za robotica 3 */
Robot_3::Robot_3(float ticksPerSecond, int player, Tacka t)
    : Robot(ticksPerSecond,player,t,Tacka(0,0,0),0,
            5*ticksPerSecond,5*ticksPerSecond,5*ticksPerSecond,5*ticksPerSecond,
            Tacka(0,0,-15),Tacka(15,0,0),Tacka(0,0,15),Tacka(-15,0,0),15)
{
    _ability01=new Robot3_ability1();//100,20);//5*ticksPerSecond,ticksPerSecond);
    _ability02=new Robot3_ability2();//100,20);//5*ticksPerSecond,ticksPerSecond);

}


/* Animacija i izracunavanje za robotic 3, izvrsava se u klasi animationTimer */
/*void Robot_3::animation()
{

    this->_energy+=5.0/_ticksPerSecond;
    if(this->_energy > 100)
        this->_energy=100;

    //std::cout << this->_energy << std::endl;
    if(this->_ability_1>0)
        this->_ability_1--;
    if(this->_ability_2>0)
        this->_ability_2--;
    if(this->_ability_3>0)
        this->_ability_3--;
    if(this->_ability_4>0)
        this->_ability_4--;
    if(this->_left_right==KEY_LEFT)
        this->_center.add(-this->_speed,0,0);
    else if(this->_left_right==KEY_RIGHT)
        this->_center.add(this->_speed,0,0);

    if(this->_up_down==KEY_UP)
        this->_center.add(0,0,-this->_speed);

    else if(this->_up_down==KEY_DOWN)
        this->_center.add(0,0,this->_speed);

}*/


/* Iscrtavanje robotica 3 */
void Robot_3::draw()
{
    glutcpp::push();
        glutcpp::translate(this->_center);


        /*
        int ugao_naginjanja_napred_nazad=0;

        if(this->_up_down==KEY_DOWN)
            ugao_naginjanja_napred_nazad=5;
        else if(this->_up_down==KEY_UP)
            ugao_naginjanja_napred_nazad=-5;

        glutcpp::rotate(-_ugao,0,1,0);
        glutcpp::rotate(ugao_naginjanja_napred_nazad,1,0,0);*/


        /*
        int ugao_naginjanja_levo_desno=0;

        if(this->_left_right==KEY_LEFT)
            ugao_naginjanja_levo_desno=5;
        else if(this->_left_right==KEY_LEFT)
            ugao_naginjanja_levo_desno=-5;

        glutcpp::rotate(ugao_naginjanja_levo_desno,0,0,1);*/

        this->model();
        //this->ability_1();
        //this->ability_2();
        //this->ability_4();
    glutcpp::pop();

    _ability01->draw();
    _ability02->draw();
    this->ability_3();
}


/* Model robotica 3 */
void Robot_3::model()
{
    /* robotic se uvek okrece */
    glutcpp::rotate(21*this->_ugao_rotacije,0,-1,0);

    this->_ugao_rotacije++;

    /* donji deo robotica */
    glutcpp::push();
        glutcpp::color(0.5,0.5,0.5,this->_fade);
        glutcpp::translate(0,10,0);
        glutcpp::rotate(90,1,0,0);
        glutcpp::cone(15,15);
    glutcpp::pop();

    /* dekoracija kod donjeg dela robotica */
    glutcpp::push();
        glutcpp::color(0.5,0.5,0.5,this->_fade);
        glutcpp::kvadar(Tacka(5,0,5),Tacka(-5,0,5),Tacka(-5,0,-5),Tacka(5,0,-5),
                     Tacka(5,1,5),Tacka(-5,1,5),Tacka(-5,1,-5),Tacka(5,1,-5));
        glutcpp::rotate(45,0,1,0);
        glutcpp::kvadar(Tacka(5,0,5),Tacka(-5,0,5),Tacka(-5,0,-5),Tacka(5,0,-5),
                     Tacka(5,1,5),Tacka(-5,1,5),Tacka(-5,1,-5),Tacka(5,1,-5));
    glutcpp::pop();

    /* gornji deo robotica */
    glutcpp::push();
        glutcpp::color(0.1,0.1,0.1,this->_fade);
        glutcpp::translate(0,12,0);
        glutcpp::rotate(90,1,0,0);
        glutcpp::cylinder(15,2);
    glutcpp::pop();
}


/* MELEE ABILITY */
/* Nozici */
void Robot_3::ability_1()
{
    /* promenljive za poziciju nozveva */
    this->_radius_nozevi=0;
    float number=0;
    if(this->_ability_1>4*_ticksPerSecond)
        number=5*_ticksPerSecond-this->_ability_1;
    else if(this->_ability_1>3.5*_ticksPerSecond)
        number=_ticksPerSecond;
    else if(this->_ability_1>2.5*_ticksPerSecond)
        number=this->_ability_1 - 2.5*_ticksPerSecond;
    else
        number=0;
    number=number/_ticksPerSecond;

    /* potrebno za koliziju */
    this->_radius_nozevi=15.0*number+10;

    /* ako je number veci od 0, onda su nozevi aktivirani */
    if(number > 0)
    {
        glutcpp::push();
            glutcpp::translate(0,11,0);

            /* odredjivanje boje nozica */
            /* _lava ce biti true kada je ability 4 aktiviran */
            if(this->_lava==true)
                glutcpp::color(2,0,0,1);
            else
                glutcpp::color(0.5,0.5,0.5,this->_fade);

            /* nozici robota */
            for(int i=0;i<8;i++)
            {
                glutcpp::push();
                    glutcpp::rotate(i*45,0,1,0);
                    glutcpp::translate(0,0,15.0*number);
                    glutcpp::kvadar(Tacka(0,0.5,0),Tacka(0,0.5,0),Tacka(0,0,10),Tacka(5,0.5,0),
                                 Tacka(0,-0.5,0),Tacka(0,-0.5,0),Tacka(0,0,10),Tacka(5,-0.5,0));
                glutcpp::pop();
            }
        glutcpp::pop();
    }

    /* test *//*
    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(0,5,0);
        glutcpp::translate(Tacka(-_radius_nozevi,0,0));
        glutcpp::cube(5);
    glutcpp::pop();*/
}


/* RANGE ABILITY */
/* Kruzni Laser */
void Robot_3::ability_2()
{
    /* promenljiva potrebna za koliziju */
    this->_radius_laser=0;

    /* laser traje kratko */
    if(this->_ability_2 > 4.5*_ticksPerSecond)
    {
        /* laser - velicina u zavisnosti od tikova */
        glutcpp::push();
            float number=(float)this->_ability_2/this->_ability_2_cooldown;
            glutcpp::color(0,1,0,number-0.2);
            glutcpp::translate(0,10,0);
            glutcpp::rotate(90,1,0,0);
            glutcpp::cylinder((1.0-number)*1000,1);
        glutcpp::pop();

        /* za koliziju */
        this->_radius_laser=(1.0-number)*1000;
    }

    /* test *//*
    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(0,5,0);
        glutcpp::translate(Tacka(-_radius_laser,0,0));
        glutcpp::cube(5);
    glutcpp::pop();*/
}


/* DEFENSIVE ABILITY */
/* Fade Shield */
void Robot_3::ability_3()
{
    /* odredjivanje providnosti robotica */
    this->_fade=1.0;
    if(this->_ability_3 > 0)
    {
        float number=(float)this->_ability_3/this->_ability_3_cooldown;
        number=number/2.0;
        this->_fade=1.0-number;
    }

}


/* SPECIAL ABILITY */
/* Speed + Lava nozevi */
void Robot_3::ability_4()
{
    /* ako je aktiviran ability 4 */
    if(this->_ability_4 > 0)
    {
        /* povecavamo brzinu i postavljamo nozeve na lava (crvenu boju) */
        this->_speed=200/_ticksPerSecond;
        this->_lava=true;

        /* postavljamo ability 1 na odredjen broj, jer ability 4 koristi ability 1 samo pojacan */
        this->_ability_1=4*_ticksPerSecond;
    }
    else
    {
        this->_speed=100/_ticksPerSecond;
        this->_lava=false;
    }
}
