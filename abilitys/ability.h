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


/* ukljucujemo potrebna zaglavlja */
#include "../glutcpp/tacka.h"
#include "../glutcpp/glutAnimationTimer.h"
#include "../prepreka.h"
#include <vector>
#include "../telo.h"


/* Nadklasa za abilitys */
class Ability
{
public:
    /* konstruktor koji prima vreme kolko dugo se ceka za sledece koriscenje,
     * kolko puta u sekundi se iscrtava, radius od ability i tacku gde je centar udara */
    Ability(int cooldown,int ticksPerSecond,int radius,Tacka tackaSudara);

    /* dekonstruktor */
    virtual ~Ability() {}

    /* Racunanje povrsine pomocu 4 trouglova, gde je spoljna u svakom trouglu */
    double povrsina(const Tacka &NW, const Tacka &NE,
                      const Tacka &SW, const Tacka &SE, const Tacka &spoljna);

    /* posebna obrada kolizije, ako radius postoji za koliziju */
    bool kolizijaRadius(Telo & t);

    /* kolizija za sva tela i ability */
    bool kolizija(Telo & t);

    /* crtanje ability */
    virtual void draw() {}

    /* crtanje za debug*/
    void testDraw();

    /* crtanje za debug*/
    void testRadius();

    /* getteri */
    Tacka getTackaSudara();
    int getCooldown();
    int getTime();
    int getDamage();

    /* animacija za ability menja vreme i namesta promenljive za TackuSudara */
    void animation(Tacka _centar_robota, float _ugao_robota);

    /* dodatna animacija za specijalizovanu ability */
    virtual void animation2(Tacka _centar_robota, float _ugao_robota) {_centar_robota=_centar_robota;_ugao_robota=_ugao_robota;}

    /* koriscenje ability ako je moguce */
    bool use();

protected:

    /* kolko dugo se ceka pre ponovog koriscenja */
    int _cooldown=100;

    /* kolko puta u sekundi se iscrtava */
    int _ticksPerSecond=20;

    /* radius za ability */
    int _radius=0;

    /* centar tacke sudara od ability */
    Tacka _tackaSudara=Tacka(0,0,0);

    /* ugao robota */
    float _ugao=0;

    /* centar robota */
    Tacka _center=Tacka(0,0,0);

    /* vreme proteklo od koriscenja ability */
    int _time=0;

    /* da li radi dmg i za neke abilitys, da li se iscrtava */
    bool _exist=false;

    /* kolko damage radi ability */
    int _damage=10;

    /* pomocna promenljiva za racunanje */
    float _number=0;
};


#include "ability.cpp"


#endif // ABILITY_H
