#ifndef ROBOT3_ABILITY1_H
#define ROBOT3_ABILITY1_H

#include "ability.h"

class Robot3_ability1 : public Ability
{
public:
    Robot3_ability1();
    ~Robot3_ability1() {}
    void animation2(Tacka _centar_robota, float _ugao_robota);
    void draw();
};

#include "robot3_ability1.cpp"

#endif // ROBOT3_ABILITY1_H
