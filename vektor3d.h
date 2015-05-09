#ifndef VEKTOR3D_H
#define VEKTOR3D_H

/*Klasa koja sadrzi funkcije za rad s vektorima*/

#include "glutcpp/tacka.h"

class Vektor3D
{
public:

    /*Konstruise vektor AB od tacaka A i B*/
    static Tacka vektor(Tacka A, Tacka B);

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
};


#include "vektor3d.cpp"

#endif // VEKTOR3D_H
