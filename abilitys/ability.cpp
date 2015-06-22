
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


bool Ability::kolizijaRadius(Telo & t)
{
    if(_exist==false)
        return false;

    double eps = 1;

    Tacka p1=provera::position(Tacka(_radius,0,0),getTackaSudara(),_ugao);
    Tacka p2=provera::position(Tacka(-_radius,0,0),getTackaSudara(),_ugao);
    Tacka p3=provera::position(Tacka(0,0,_radius),getTackaSudara(),_ugao);
    Tacka p4=provera::position(Tacka(0,0,-_radius),getTackaSudara(),_ugao);

    Tacka prviNW = provera::position(t.getNW(), t.getPos(), t.getUgao());
    Tacka prviNE = provera::position(t.getNE(), t.getPos(), t.getUgao());
    Tacka prviSW = provera::position(t.getSW(), t.getPos(), t.getUgao());
    Tacka prviSE = provera::position(t.getSE(), t.getPos(), t.getUgao());

    if (fabs(povrsina(prviNW, prviNE, prviSW, prviSE, p1) - t.getPovrsina()) < eps)
    {
        _exist=false;
        return true;
    }
    if (fabs(povrsina(prviNW, prviNE, prviSW, prviSE, p2) - t.getPovrsina()) < eps)
    {
        _exist=false;
        return true;
    }
    if (fabs(povrsina(prviNW, prviNE, prviSW, prviSE, p3) - t.getPovrsina()) < eps)
    {
        _exist=false;
        return true;
    }
    if (fabs(povrsina(prviNW, prviNE, prviSW, prviSE, p4) - t.getPovrsina()) < eps)
    {
        _exist=false;
        return true;
    }

    if(fabs(Vektor3D::duzina(prviNW,_center))<=_radius)
    {
        _exist=false;
        return true;
    }
    if(fabs(Vektor3D::duzina(prviNE,_center))<=_radius)
    {
        _exist=false;
        return true;
    }
    if(fabs(Vektor3D::duzina(prviSW,_center))<=_radius)
    {
        std::cout << "7" << std::endl;
        _exist=false;
        return true;
    }
    if(fabs(Vektor3D::duzina(prviSE,_center))<=_radius)
    {
        _exist=false;
        return true;
    }

    return false;
}



bool Ability::kolizija(Telo & t)
{
    if(_exist==false)
        return false;


    if(_radius > -1)
        return kolizijaRadius(t);


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
#ifdef DEBUG_MODELS
    if(_radius>0)
    {
        testRadius();
        //return;
    }

    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(getTackaSudara());
        glutcpp::cube(5);
    glutcpp::pop();
#endif
}


void Ability::testRadius()
{
    Tacka p1=provera::position(Tacka(_radius,0,0),getTackaSudara(),_ugao);
    Tacka p2=provera::position(Tacka(-_radius,0,0),getTackaSudara(),_ugao);
    Tacka p3=provera::position(Tacka(0,0,_radius),getTackaSudara(),_ugao);
    Tacka p4=provera::position(Tacka(0,0,-_radius),getTackaSudara(),_ugao);



    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(p1);
        glutcpp::cube(5);
    glutcpp::pop();



    glutcpp::push();
        glutcpp::color(1,0,0,1);
        glutcpp::translate(p2);
        glutcpp::cube(5);
    glutcpp::pop();



    glutcpp::push();
        glutcpp::color(0,1,0,1);
        glutcpp::translate(p3);
        glutcpp::cube(5);
    glutcpp::pop();



    glutcpp::push();
        glutcpp::color(0,0,1,1);
        glutcpp::translate(p4);
        glutcpp::cube(5);
    glutcpp::pop();
}
