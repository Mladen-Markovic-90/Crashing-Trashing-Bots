#ifndef ROBOT2_ABILITY1_H
#define ROBOT2_ABILITY1_H

#include "ability.h"

class Robot2_ability1 : public Ability
{
public:
    Robot2_ability1();
    ~Robot2_ability1() {}

    void animation2(Tacka _centar_robota, float _ugao_robota);
    void draw();

private:
    /* sluzi za poziciju udarca kolca */
    Tacka tacka_kolac=Tacka(0,0,0);
};


#include "robot2_ability1.cpp"

#endif // ROBOT2_ABILITY1_H
