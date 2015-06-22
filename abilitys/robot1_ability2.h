#ifndef ROBOT1_ABILITY2_H
#define ROBOT1_ABILITY2_H

#include "ability.h"

class Robot1_ability2 : public Ability
{
public:
    Robot1_ability2();//int cooldown,int ticksPerSecond);
    ~Robot1_ability2() {}

    void draw();

    void animation2(Tacka _centar_robota, float _ugao_robota);
private:
    /* sluzi za poziciju i rotaciju rakete */
    Tacka tacka_raketa=Tacka(0,0,0);
    Tacka tacka_raketa_help=Tacka(0,0,0);
    int ugao_raketa=0;
};


#include "robot1_ability2.cpp"

#endif // ROBOT1_ABILITY2_H
