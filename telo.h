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


#ifndef TELO_H
#define TELO_H

#include "glutcpp/tacka.h"

class Telo
{
public:
    Telo(Tacka northWest, Tacka northEast, Tacka southEast , Tacka southWest,
         float radius, Tacka center, float _ugao);
    virtual ~Telo() {}

    double getPovrsina() const { return _povrsina; }

    Tacka getNW() const { return _northWest; }
    Tacka getNE() const { return _northEast; }
    Tacka getSW() const { return _southWest; }
    Tacka getSE() const { return _southEast; }

    //TODO: PODESITI OSTALE PARAMETRE KASNIJE KADA BUDU NAPRAVLJENI
    void setUgao(float ugao) {_ugao=ugao;}
    void setPos(Tacka t) {_center=t;}
    //END TODO


    /* Getter za centar robotica */
    Tacka getPos() const { return _center; }

    /* Getter za ugao koji sluzi za rotaciju robotica */
    float getUgao() const { return _ugao; }


    /* pretraga za koliziju */
    double pretraga(const Telo &drugi, const Tacka &pomeraj,
            double min_k, double max_k, int dubina);
    /* racuna povrsinu za koliziju*/
    double povrsina(const Tacka &NW, const Tacka &NE,
            const Tacka &SW, const Tacka &SE, const Tacka &spoljna);

    /* AGRADZAG */
    bool kolizija(const Telo &t, const Tacka &pomeraj);

    /* provera crtanja tacki */
    void testDraw(int y);

protected:
    /* krajnje tacke robotica i radius */
    Tacka _northWest;
    Tacka _northEast;
    Tacka _southEast;
    Tacka _southWest;
    float _radius;

    /* povrsina robotica za koliziju */
    double _povrsina=0;

    /* Centar robota */
    Tacka _center;

    /* Ugao koji sluzi za rotaciju robotica */
    float _ugao;
};

#include "telo.cpp"

#endif // TELO_H
