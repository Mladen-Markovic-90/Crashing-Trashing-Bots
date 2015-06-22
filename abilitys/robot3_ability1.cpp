#include "robot3_ability1.h"
#include "ability.h"

Robot3_ability1::Robot3_ability1()
    : Ability(100,20,0 , Tacka(0,0,0) )
{_damage=15;}





/* MELEE ABILITY */
/* Nozici */
void Robot3_ability1::draw()
{

    //if(_exist==false)
       // return;
    /* promenljive za poziciju nozveva */
    /*this->_radius_nozevi=0;
    float number=0;
    if(this->_ability_1>4*_ticksPerSecond)
        number=5*_ticksPerSecond-this->_ability_1;
    else if(this->_ability_1>3.5*_ticksPerSecond)
        number=_ticksPerSecond;
    else if(this->_ability_1>2.5*_ticksPerSecond)
        number=this->_ability_1 - 2.5*_ticksPerSecond;
    else
        number=0;
    number=number/_ticksPerSecond;*/

    /* potrebno za koliziju */
    //this->_radius_nozevi=15.0*number+10;

    /* ako je number veci od 0, onda su nozevi aktivirani */
    if(_time > 0)
    {
        glutcpp::push();
            glutcpp::translate(0,11,0);
            glutcpp::translate(_center);

            /* odredjivanje boje nozica */
            /* _lava ce biti true kada je ability 4 aktiviran */
            /*if(this->_lava==true)
                glutcpp::color(2,0,0,1);
            else
                glutcpp::color(0.5,0.5,0.5,this->_fade);*/
            glutcpp::color(0.5,0.5,0.5,1);

            glutcpp::rotate(21*_time,0,1,0);

            /* nozici robota */
            for(int i=0;i<8;i++)
            {
                glutcpp::push();
                    glutcpp::rotate(i*45,0,1,0);
                    glutcpp::translate(0,0,15.0*_number);
                    glutcpp::kvadar(Tacka(0,0.5,0),Tacka(0,0.5,0),Tacka(0,0,10),Tacka(5,0.5,0),
                                 Tacka(0,-0.5,0),Tacka(0,-0.5,0),Tacka(0,0,10),Tacka(5,-0.5,0));
                glutcpp::pop();
            }
        glutcpp::pop();
    }

    testDraw();

    /* test *//*
    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(0,5,0);
        glutcpp::translate(Tacka(-_radius_nozevi,0,0));
        glutcpp::cube(5);
    glutcpp::pop();*/
}

void Robot3_ability1::animation2(Tacka _centar_robota, float _ugao_robota)
{
    _center=_centar_robota;
    _ugao=_ugao_robota;

    /* promenljive za poziciju nozveva */
    _number=0;
    if(_time>4*_ticksPerSecond)
        _number=5*_ticksPerSecond-_time;
    else if(_time>3.5*_ticksPerSecond)
        _number=_ticksPerSecond;
    else if(_time>2.5*_ticksPerSecond)
        _number=_time - 2.5*_ticksPerSecond;
    else
        _number=0;
    _number=_number/_ticksPerSecond;

    /* potrebno za koliziju */
    _radius=15.0*_number+10;
}
