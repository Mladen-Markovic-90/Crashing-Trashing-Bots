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
