#ifndef ABILITY_H
#define ABILITY_H

//TODO: cemu bese sluzi ova klasa?

#include "../glutcpp/tacka.h"
#include "../glutcpp/glutAnimationTimer.h"
#include "../prepreka.h"
#include <vector>
#include "../telo.h"

class Ability
{
public:
    Ability(int cooldown,int ticksPerSecond,int radius,Tacka tackaSudara);
    virtual ~Ability() {}

    double povrsina(const Tacka &NW, const Tacka &NE,
                      const Tacka &SW, const Tacka &SE, const Tacka &spoljna);

    bool kolizijaRadius(Telo & t);

    bool kolizija(Telo & t);

    virtual void draw() {}

    void testDraw();

    void testRadius();

    Tacka getTackaSudara();

    int getCooldown();

    void animation(Tacka _centar_robota, float _ugao_robota);
    virtual void animation2(Tacka _centar_robota, float _ugao_robota) {_centar_robota=_centar_robota;_ugao_robota=_ugao_robota;}

    int getTime();

    bool use();//float & energy);

    int getDamage();

protected:


    int _cooldown=100;
    int _ticksPerSecond=20;
    int _radius=0;

    Tacka _tackaSudara=Tacka(0,0,0);
    float _ugao=0;
    Tacka _center=Tacka(0,0,0);

    int _time=0;
    int _cost=0;

    bool _exist=false;

    int _damage=10;

    float _number=0;


};

#include "ability.cpp"

#endif // ABILITY_H
