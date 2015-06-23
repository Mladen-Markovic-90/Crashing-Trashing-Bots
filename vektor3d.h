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


#ifndef VEKTOR3D_H
#define VEKTOR3D_H

/*Klasa koja sadrzi funkcije za rad s vektorima*/

#include "glutcpp/tacka.h"

class Vektor3D
{
public:

    /*Konstruise vektor AB od tacaka A i B*/
    static Tacka vektor(Tacka A, Tacka B);

    static Tacka rotate2D(Tacka v, float ugao);
    
    /*Duzina vektora*/
    static double duzina(Tacka vektor);
    /*Duzina vektora AB*/
    static double duzina(Tacka A, Tacka B);

    /*Vraca jedinicni vektor*/
    static Tacka jedinicni(Tacka vektor);

    static Tacka jedinicni(Tacka A, Tacka B);

    /*Skalarni proizvod(dot product) vx*ux+vy*uy+vz*uz */
    static double skalarniProizvod(Tacka vektor1, Tacka vektor2);
    /*Skalarni proizvod vektora AB i CD*/
    static double skalarniProizvod(Tacka A, Tacka B, Tacka C, Tacka D);

    /*Ugao izmedju dva vektora*/
    static double ugao (Tacka vektor1, Tacka vektor2);
    /*Ugao izmedju vektora AB i CD*/
    static double ugao (Tacka A, Tacka B, Tacka C, Tacka D);

    /*Vektorski proizvod(cross product) (iz determinante:) */
    static Tacka vektorskiProizvod(Tacka vektor1, Tacka vektor2);

    static Tacka vektorskiProizvod(Tacka A, Tacka B, Tacka C, Tacka D);

    /*Vraca vektor normalan na ravan koju formiraju zadati vektori*/
    static Tacka normala(Tacka vektor1, Tacka vektor2);

    static Tacka normala(Tacka A, Tacka B, Tacka C, Tacka D);

    static double cos_fi(Tacka vektor1, Tacka vektor2);
};


#include "vektor3d.cpp"

#endif // VEKTOR3D_H
