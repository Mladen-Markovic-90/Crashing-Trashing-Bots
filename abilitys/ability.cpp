
#include "../telo.h"
#include "../prepreka.h"
#include "ability.h"
#include <vector>


Ability::Ability(int cooldown, int ticksPerSecond, int radius,Tacka tackaSudara)
    :_cooldown(cooldown) , _ticksPerSecond(ticksPerSecond) , _radius(radius) , _tackaSudara(tackaSudara)
{}


double Ability::povrsina(const Tacka &NW, const Tacka &NE,
                  const Tacka &SW, const Tacka &SE, const Tacka &spoljna)
{
    double P = 0;
    P += provera::povrsina(NW, SW, spoljna);
    P += provera::povrsina(SW, SE, spoljna);
    P += provera::povrsina(SE, NE, spoljna);
    P += provera::povrsina(NE, NW, spoljna);

    //    std::cout << P << std::endl;
    return P;
}


void Ability::kolizijaPrepreka(Prepreka & t)
{
    if(_exist==false)
    {
        //std::cout << "false" << std::endl;
        return;
    }
    //std::cout << "true" << std::endl;
    double eps = 1;

    //Tacka drugi=provera::position(_tackaSudara,_center,_ugao);

    Tacka drugi=getTackaSudara();

    Tacka prviNW = provera::position(t.getNW(), t.getPos(), t.getUgao());
    Tacka prviNE = provera::position(t.getNE(), t.getPos(), t.getUgao());
    Tacka prviSW = provera::position(t.getSW(), t.getPos(), t.getUgao());
    Tacka prviSE = provera::position(t.getSE(), t.getPos(), t.getUgao());

    if (fabs(povrsina(prviNW, prviNE, prviSW, prviSE, drugi) - t.getPovrsina()) < eps)
        _exist=false;

    //std::cout << povrsina(prviNW, prviNE, prviSW, prviSE, drugi) << " ILI " << t.getPovrsina() << std::endl;
    return;
}



bool Ability::kolizija(Telo & t)
{
    if(_exist==false)
        return false;
    double eps = 1;

    Tacka drugi=getTackaSudara();

    Tacka prviNW = provera::position(t.getNW(), t.getPos(), t.getUgao());
    Tacka prviNE = provera::position(t.getNE(), t.getPos(), t.getUgao());
    Tacka prviSW = provera::position(t.getSW(), t.getPos(), t.getUgao());
    Tacka prviSE = provera::position(t.getSE(), t.getPos(), t.getUgao());

    if (fabs(povrsina(prviNW, prviNE, prviSW, prviSE, drugi) - t.getPovrsina()) < eps)
    {
        _exist=false;
        return true;
    }

    return false;
}



int Ability::getDamage()
{
    return _damage;
}


int Ability::getCooldown()
{
    return _cooldown;
}

void Ability::animation(Tacka _centar_robota, float _ugao_robota)
{
    if(_time > 0)
        _time--;
    if(_time <= 0)
        _exist=false;
    animation2(_centar_robota,_ugao_robota);
}

int Ability::getTime()
{
    return _time;
}

bool Ability::use()
{
    if(_time<=0)
    {
        _exist=true;
        _time=_cooldown;
        return true;
    }
    return false;
}


Tacka Ability::getTackaSudara()
{
    return provera::position(_tackaSudara,_center,_ugao);
}

void Ability::testDraw()
{
    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(getTackaSudara());
        glutcpp::cube(5);
    glutcpp::pop();

}
