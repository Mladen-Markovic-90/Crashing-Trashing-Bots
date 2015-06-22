#ifndef ROBOT1_ABILITY1_H
#define ROBOT1_ABILITY1_H


#include "ability.h"

class Robot1_ability1 : public Ability
{
public:
    Robot1_ability1();//int cooldown,int ticksPerSecond);
    ~Robot1_ability1() {}
    void animation2(Tacka _centar_robota, float _ugao_robota);
    void draw();

private:
    int cekic_radius=5;
    Tacka tacka_cekic=Tacka(0,0,-30);

};


#include "robot1_ability1.cpp"

#endif // ROBOT1_ABILITY1_H
