#include "robot2_ability2.h"

Robot2_ability2::Robot2_ability2()
{

}

Robot2_ability2::~Robot2_ability2()
{

}

Robot2_ability2::Draw(Tacka _centar_robota, float _ugao_robota)
{
    /* NOTE tacka udarca provera::position(tacka_laser,tacka_laser_help,ugao_laser) */
    /* RANGE ABILITY */
    /* Raketa */

    /* pozicija i ugao rakete */
    float number=0;
    if(this->_ability_2>0)
        number=5*_ticksPerSecond-this->_ability_2;
    else
    {
        this->ugao_laser=this->_ugao-90;
        this->tacka_laser_help=_center;
    }

    number*=10;
    this->tacka_laser=Tacka(15,0,0)+Tacka(1,0,0)*number;

    if(number>0)
    {
        glutcpp::push();
            /* postavljamo laser na odredjeno mesto */
            glutcpp::translate(this->tacka_laser_help);
            glutcpp::translate(0,5,0);

            glutcpp::rotate(-this->ugao_laser,0,1,0);
            glutcpp::translate(tacka_laser);
            glutcpp::translate(Tacka(-15,0,0));


            /* Laser */
            glutcpp::rotate(90,0,1,0);
            glutcpp::color(0.5,0.5,2,1);
            glutcpp::cylinder(0.5,15);

        glutcpp::pop();
    }


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
