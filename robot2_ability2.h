#ifndef ROBOT2_ABILITY2_H
#define ROBOT2_ABILITY2_H

#include "ability.h"

class Robot2_ability2 : public Ability
{
public:
    Robot2_ability2();
    ~Robot2_ability2() {}

    void draw();
    void animation2(Tacka _centar_robota, float _ugao_robota);

private:
    /* sluzi za poziciju i rotaciju lasera */
    Tacka tacka_laser=Tacka(0,0,0);
    Tacka tacka_laser_help=Tacka(0,0,0);
    int ugao_laser=0;
};



#include "robot2_ability2.cpp"

#endif // ROBOT2_ABILITY2_H
