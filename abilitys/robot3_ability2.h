#ifndef ROBOT3_ABILITY2_H
#define ROBOT3_ABILITY2_H

#include "ability.h"


class Robot3_ability2 : public Ability
{
public:
    Robot3_ability2();
    ~Robot3_ability2() {}
    void animation2(Tacka _centar_robota, float _ugao_robota);
    void draw();
};

#include "robot3_ability2.cpp"

#endif // ROBOT3_ABILITY2_H
