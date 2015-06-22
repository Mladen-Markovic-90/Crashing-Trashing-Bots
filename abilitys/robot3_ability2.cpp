#include "robot3_ability2.h"
#include "ability.h"

Robot3_ability2::Robot3_ability2()
    : Ability(100,20,0 , Tacka(0,0,0) )
{}



void Robot3_ability2::draw()
{
    if(_exist==false)
        return;

    /* promenljiva potrebna za koliziju */
    //this->_radius_laser=0;

    /* laser traje kratko */
    if(_time > 4.5*_ticksPerSecond)
    {
        /* laser - velicina u zavisnosti od tikova */
        glutcpp::push();
            glutcpp::color(0,1,0,_number-0.2);
            glutcpp::translate(0,10,0);
            glutcpp::translate(_center);
            glutcpp::rotate(90,1,0,0);
            glutcpp::cylinder((1.0-_number)*1000,1);
        glutcpp::pop();

    }

    /* test *//*
    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(0,5,0);
        glutcpp::translate(Tacka(-_radius_laser,0,0));
        glutcpp::cube(5);
    glutcpp::pop();*/



}


void Robot3_ability2::animation2(Tacka _centar_robota, float _ugao_robota)
{
    _center=_centar_robota;
    _ugao=_ugao_robota;

    _radius=0;

    if(_time > 4.5*_ticksPerSecond)
        {
        _number=(float)_time/_cooldown;
        /* za koliziju */
        _radius=(1.0-_number)*1000;
        }


}
