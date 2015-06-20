#include "robot1_ability1.h"

Robot1_ability1::Robot1_ability1()
{

}

Robot1_ability1::~Robot1_ability1()
{

}

Robot1_ability1::Draw()
{
    /* NOTE: tacka udarca -> provera::position(tacka_cekic,_center,_ugao) i cekic_radius */
    /* MELEE ABILITY */
    /* Cekic */

    /* odredjivanje ugla cekica */
    float ugao_cekic;
    if(this->_ability_1>4.5*_ticksPerSecond)
        ugao_cekic=(this->_ability_1 - 4.5*_ticksPerSecond)*2;
    else if(this->_ability_1>2.5*_ticksPerSecond)
        ugao_cekic=(4.5*_ticksPerSecond - this->_ability_1)/2;
    else
        ugao_cekic=_ticksPerSecond;
    ugao_cekic=ugao_cekic/_ticksPerSecond;

    glutcpp::push();
        glutcpp::translate(this->_center);
        glutcpp::rotate(-this->_ugao,0,1,0);
        glutcpp::rotate(90,0,1,0);

        glutcpp::translate(10,13,0);
        glutcpp::rotate(90*ugao_cekic,0,0,1);

        glutcpp::color(0.2,0.2,0.2,1);

        /* levi drzac cekica */
        glutcpp::push();
            glutcpp::translate(0,0,-15);
            glutcpp::kvadar(Tacka(-1,-1,0),Tacka(1,-1,0),Tacka(1,1,0),Tacka(-1,1,0),
                         Tacka(-1,-1,5),Tacka(1,-1,5),Tacka(1,1,5),Tacka(-1,1,5));
            glutcpp::kvadar(Tacka(-1,-1,-1),Tacka(-1,1,-1),Tacka(-1,1,1),Tacka(-1,-1,1),
                         Tacka(20,-1,-1),Tacka(20,1,-1),Tacka(20,1,1),Tacka(20,-1,1));
        glutcpp::pop();

        /* desni drzac cekica */
        glutcpp::push();
            glutcpp::translate(0,0,15);
            glutcpp::kvadar(Tacka(-1,-1,0),Tacka(1,-1,0),Tacka(1,1,0),Tacka(-1,1,0),
                         Tacka(-1,-1,-5),Tacka(1,-1,-5),Tacka(1,1,-5),Tacka(-1,1,-5));
            glutcpp::kvadar(Tacka(-1,-1,-1),Tacka(-1,1,-1),Tacka(-1,1,1),Tacka(-1,-1,1),
                         Tacka(20,-1,-1),Tacka(20,1,-1),Tacka(20,1,1),Tacka(20,-1,1));
        glutcpp::pop();

        /* donja kupa cekica */
        glutcpp::push();
            glutcpp::translate(20,-8,0);
            glutcpp::rotate(90,-1,0,0);
            glutcpp::cone(10,15);
        glutcpp::pop();

        /* gornja kupa cekica */
        glutcpp::push();
            glutcpp::translate(20,8,0);
            glutcpp::rotate(90,1,0,0);
            glutcpp::cone(10,15);
        glutcpp::pop();

        /* sipka koja prolazi kroz cekic */
        glutcpp::push();
            glutcpp::translate(19,0,0);
            glutcpp::kvadar(2,30,2);
        glutcpp::pop();

    glutcpp::pop();



    /* test *//*
    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(provera::position(tacka_cekic,_center,_ugao));
        glutcpp::rotate(90,1,0,0);
        glutcpp::cylinder(10,1);
    glutcpp::pop();*/
}
