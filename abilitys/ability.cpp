/*
    Crashing Trashing Bots is a 3D game in freeglut
    Copyright (C) 2015 Mladen Markovic,Tamara Plazinic,Nikola Banjac

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/* ukljucujemo potrebna zaglavlja */
#include "../telo.h"
#include "../prepreka.h"
#include "ability.h"
#include <vector>


/* konstruktor koji prima vreme kolko dugo se ceka za sledece koriscenje,
 * kolko puta u sekundi se iscrtava, radius od ability i tacku gde je centar udara */
Ability::Ability(int cooldown, int ticksPerSecond, int radius,Tacka tackaSudara)
    :_cooldown(cooldown) , _ticksPerSecond(ticksPerSecond) , _radius(radius) , _tackaSudara(tackaSudara)
{}


/* Racunanje povrsine pomocu 4 trouglova, gde je spoljna u svakom trouglu */
double Ability::povrsina(const Tacka &NW, const Tacka &NE,
                  const Tacka &SW, const Tacka &SE, const Tacka &spoljna)
{
    double P = 0;
    P += provera::povrsina(NW, SW, spoljna);
    P += provera::povrsina(SW, SE, spoljna);
    P += provera::povrsina(SE, NE, spoljna);
    P += provera::povrsina(NE, NW, spoljna);
    return P;
}


/* posebna obrada kolizije, ako radius postoji za koliziju */
bool Ability::kolizijaRadius(Telo & t)
{
    if(_exist==false)
        return false;

    double eps = 1;

    /* aproksimacija 4 tacke za ability */
    Tacka p1=provera::position(Tacka(_radius,0,0),getTackaSudara(),_ugao);
    Tacka p2=provera::position(Tacka(-_radius,0,0),getTackaSudara(),_ugao);
    Tacka p3=provera::position(Tacka(0,0,_radius),getTackaSudara(),_ugao);
    Tacka p4=provera::position(Tacka(0,0,-_radius),getTackaSudara(),_ugao);

    /* izracunamo tacke za telo */
    Tacka prviNW = provera::position(t.getNW(), t.getPos(), t.getUgao());
    Tacka prviNE = provera::position(t.getNE(), t.getPos(), t.getUgao());
    Tacka prviSW = provera::position(t.getSW(), t.getPos(), t.getUgao());
    Tacka prviSE = provera::position(t.getSE(), t.getPos(), t.getUgao());

    /* provera povrsine */
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

    /* provera za radius */
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


/* kolizija za sva tela i ability */
bool Ability::kolizija(Telo & t)
{
    if(_exist==false)
        return false;

    /* ako postoji radius, onda moramo obraditi koliziju drugacije */
    if(_radius > -1)
        return kolizijaRadius(t);


    double eps = 1;

    /* izdvajamo samo centar gde udara od ability */
    Tacka drugi=getTackaSudara();

    /* izracunamo tacke za telo */
    Tacka prviNW = provera::position(t.getNW(), t.getPos(), t.getUgao());
    Tacka prviNE = provera::position(t.getNE(), t.getPos(), t.getUgao());
    Tacka prviSW = provera::position(t.getSW(), t.getPos(), t.getUgao());
    Tacka prviSE = provera::position(t.getSE(), t.getPos(), t.getUgao());

    /* proverimo povrsinu */
    if (fabs(povrsina(prviNW, prviNE, prviSW, prviSE, drugi) - t.getPovrsina()) < eps)
    {
        _exist=false;
        return true;
    }

    return false;
}


/* getter za damage */
int Ability::getDamage()
{
    return _damage;
}


/* getter za cooldown */
int Ability::getCooldown()
{
    return _cooldown;
}


/* animacija za ability menja vreme i namesta promenljive za Tackusudara */
void Ability::animation(Tacka _centar_robota, float _ugao_robota)
{
    if(_time > 0)
        _time--;
    if(_time <= 0)
        _exist=false;
    animation2(_centar_robota,_ugao_robota);
}


/* getter za vreme */
int Ability::getTime()
{
    return _time;
}


/* koriscenje ability ako je moguce */
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


/* izracunavamo tacku sudara */
Tacka Ability::getTackaSudara()
{
    return provera::position(_tackaSudara,_center,_ugao);
}


/* crtanje za debug*/
void Ability::testDraw()
{
#ifdef DEBUG_MODELS
    if(_radius>-1)
        testRadius();

    glutcpp::push();
        glutcpp::color(1,1,1,1);
        glutcpp::translate(getTackaSudara());
        glutcpp::cube(5);
    glutcpp::pop();
#endif
}


/* crtanje za debug */
void Ability::testRadius()
{
#ifdef DEBUG_MODELS
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
#endif
}
