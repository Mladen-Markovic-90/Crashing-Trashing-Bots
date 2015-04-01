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


/* Klasa za robotic 1 i rad sa njim */


/* Ukljucivanje potrebnih zaglavlja */
#include "robot_1.h"
#include "delovi.h"
#include <iostream>
#include <cmath>
#include <cstdlib>


/* Konstruktor za robotica 1 */
Robot_1::Robot_1(int player,Tacka t)
    : Robot(player,t,Tacka(0,0,-20),0,5*SECOND,5*SECOND,5*SECOND,5*SECOND)
    {}


/* Iscrtavanje robotica 1 */
void Robot_1::draw()
{
    glut::push();
        glut::translate(this->_center);
        glut::rotate(-this->_ugao,0,1,0);
        glut::rotate(90,0,1,0);
        this->model();
        this->ability_1();
        this->ability_3();
    glut::pop();

    this->ability_2();
}


void Robot_1::model()
{

    /* tockovi */
    this->ugao_tocak++;
    glut::push();
        glut::translate(15,5,-15);
        Delovi::tocak(5,2,this->ugao_tocak);
        glut::translate(-30,0,0);
        Delovi::tocak(5,2,this->ugao_tocak);
        glut::translate(0,0,28);
        Delovi::tocak(5,2,this->ugao_tocak);
        glut::translate(30,0,0);
        Delovi::tocak(5,2,this->ugao_tocak);
    glut::pop();

    glut::push();
        glut::color(0.5,0.5,0.5,1);
        glut::translate(0,6,0);
        glut::kvadar(20,30,8);
    glut::pop();

    glut::push();
        glut::color(0.5,0.5,0,1);
        glut::translate(5,10,0);
        glut::kvadar(Tacka(-25,0,15),Tacka(15,0,15),Tacka(15,0,-15),Tacka(-25,0,-15),
                     Tacka(-30,5,10),Tacka(10,5,10),Tacka(10,5,-10),Tacka(-30,5,-10));
    glut::pop();

    /*
    glut::push();
        glut::color(0.2,0.2,0.2,1);
        glut::translate(20,0,0);
        glut::kvadar(Tacka(0,0,10),Tacka(10,0,10),Tacka(10,0,-10),Tacka(0,0,-10),
                     Tacka(0,15,10),Tacka(0,15,10),Tacka(0,15,-10),Tacka(0,15,-10));
    glut::pop();*/


    /*
    glut::push();
        glut::color(0.2,0.2,0.2,1);
        glut::translate(10,17,0);
        glut::cube(4);
        glut::translate(2,0,0);
        glut::rotate(90,0,1,0);
        glut::cylinder(1,10);
    glut::pop();*/
}


//NOTE: tacka udarca -> centar + Tacka(30,0,0);
void Robot_1::ability_1()
{

    float ugao_cekic;

    if(this->_ability_1>4.5*SECOND)
        ugao_cekic=(this->_ability_1 - 4.5*SECOND)*2;
    else if(this->_ability_1>2.5*SECOND)
        ugao_cekic=(4.5*SECOND - this->_ability_1)/2;
    else
        ugao_cekic=SECOND;

    ugao_cekic=ugao_cekic/(1.0*SECOND);

    glut::push();
        glut::translate(10,13,0);
        glut::rotate(90*ugao_cekic,0,0,1);

        glut::color(0.2,0.2,0.2,1);

        glut::push();
            glut::translate(0,0,-15);
            glut::kvadar(Tacka(-1,-1,0),Tacka(1,-1,0),Tacka(1,1,0),Tacka(-1,1,0),
                         Tacka(-1,-1,5),Tacka(1,-1,5),Tacka(1,1,5),Tacka(-1,1,5));
            glut::kvadar(Tacka(-1,-1,-1),Tacka(-1,1,-1),Tacka(-1,1,1),Tacka(-1,-1,1),
                         Tacka(20,-1,-1),Tacka(20,1,-1),Tacka(20,1,1),Tacka(20,-1,1));
        glut::pop();

        glut::push();
            glut::translate(0,0,15);
            glut::kvadar(Tacka(-1,-1,0),Tacka(1,-1,0),Tacka(1,1,0),Tacka(-1,1,0),
                         Tacka(-1,-1,-5),Tacka(1,-1,-5),Tacka(1,1,-5),Tacka(-1,1,-5));
            glut::kvadar(Tacka(-1,-1,-1),Tacka(-1,1,-1),Tacka(-1,1,1),Tacka(-1,-1,1),
                         Tacka(20,-1,-1),Tacka(20,1,-1),Tacka(20,1,1),Tacka(20,-1,1));
        glut::pop();

        glut::push();
            glut::translate(20,-8,0);
            glut::rotate(90,-1,0,0);
            glut::cone(10,15);
        glut::pop();

        glut::push();
            glut::translate(20,8,0);
            glut::rotate(90,1,0,0);
            glut::cone(10,15);
        glut::pop();

        glut::push();
            glut::translate(19,0,0);
            glut::kvadar(2,30,2);

        glut::pop();
    glut::pop();

}


//NOTE: tacka udarca -> this->tacka_raketa + Tacka(20,0,0);
void Robot_1::ability_2()
{

    float number=0;
    if(this->_ability_2>0)
        number=5*SECOND-this->_ability_2;
    else
    {
        this->tacka_raketa=this->_center;
        this->ugao_raketa=this->_ugao-90;
    }

    glut::push();
        glut::translate(this->tacka_raketa);
        glut::rotate(-this->ugao_raketa,0,1,0);
        glut::translate(10*number-5,5,0);
        if(number>0)
        {
            glut::color(1,0.5,0,0.5);
            for(int i=0;i<25;i++)
            {
                float x=((float)std::rand()/RAND_MAX)*5.0;
                float y=-3+((float)std::rand()/RAND_MAX)*6.0;
                float c=-1+((float)std::rand()/RAND_MAX)*2.0;
                glut::linija(Tacka(-x,-y,0),Tacka(-(3+x),-(y+c),0));
            }
        }
        glut::rotate(90,0,1,0);
        glut::color(0.5,0.5,0.5,1);
        glut::cylinder(3,15);
        glut::rotate(-90,0,1,0);
        glut::translate(15,0,0);
        glut::rotate(90,0,1,0);
        glut::color(1,0,0,0.8);
        glut::cone(5,6);
    glut::pop();


}

void Robot_1::ability_3()
{
    float number=this->_ability_3/(float)this->_ability_3_cooldown;

    std::cout << number << std::endl;

    if(this->_ability_3)
    {
        glut::push();
            glut::color(1,1,1,0.8*number);
            glut::translate(-2.5,10,0);
            glut::kvadar(50,30,20);
        glut::pop();
    }

}
