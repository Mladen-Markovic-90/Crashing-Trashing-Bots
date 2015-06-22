#include "robot2_ability2.h"
#include "provera.h"

Robot2_ability2::Robot2_ability2()
    : Ability(100,20,0 , Tacka(15,0,0))
{}


void Robot2_ability2::draw()
{
    if(_time <= 0 || _exist==false)
        return;
    /* NOTE tacka udarca provera::position(tacka_laser,tacka_laser_help,ugao_laser) */
    /* RANGE ABILITY */
    /* Raketa */

    /* pozicija i ugao rakete *//*
    float number=0;
    if(_time>0)
        number=5*_ticksPerSecond-_time;
    else
    {
        this->ugao_laser=_ugao_robota-90;
        this->tacka_laser_help=_centar_robota;
    }

    number*=10;
    this->tacka_laser=Tacka(15,0,0)+Tacka(1,0,0)*number;*/

    glutcpp::push();
        /* postavljamo laser na odredjeno mesto */
        glutcpp::translate(0,5,0);
        glutcpp::translate(this->_center);

        glutcpp::rotate(-_ugao,0,1,0);
        //glutcpp::translate(Tacka(-15,0,0));


        /* Laser */
        glutcpp::rotate(90,0,1,0);
        glutcpp::color(0.5,0.5,2,1);
        glutcpp::cylinder(0.5,15);

    glutcpp::pop();

    testDraw();

    /*test*//*
    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(provera::position(tacka_laser,tacka_laser_help,ugao_laser));
        glutcpp::cube(5);
    glutcpp::pop();

    glutcpp::push();
        glutcpp::color(1,0,0,1);
        glutcpp::translate(_center);
        glutcpp::cube(5);
    glutcpp::pop();*/
}



void Robot2_ability2::animation2(Tacka _centar_robota, float _ugao_robota)
{

    float number=0;
    if(_time>0)
        number=5*_ticksPerSecond-_time;
    else
    {
        this->_ugao=_ugao_robota-90;
        this->_center=_centar_robota;
    }

    number*=1.5;
    this->_center=this->_center+provera::position(Tacka(15,0,0)+Tacka(1,0,0)*number,Tacka(0,0,0),_ugao);

}
