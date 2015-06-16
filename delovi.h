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


#ifndef DELOVI_H
#define DELOVI_H


/* ukljucujemo potrebna zaglavlja */
#include "glutcpp/glutcpp.h"
#include "prepreka.h"
#include <vector>

class Delovi
{
public:
    /* tocak za robotice i njegova rotacija */
    static void tocak(float radius,float height,int rotacija,int ugao_tocak)
    {
    glutcpp::push();

        /* tocak bez dekoracije */
        glutcpp::rotate(ugao_tocak,0,1,0);
        glutcpp::rotate(-rotacija*5,0,0,1);
        glutcpp::color(0.8,0.8,0.8,1);
        glutcpp::cylinder(radius,height);
        glutcpp::translate(0,0,-0.1);
        glutcpp::color(0,0,0,1);

        /* dekoracija za tocak */
        for(int i=0;i<4;i++)
        {
            glutcpp::push();
                glutcpp::rotate(i*45,0,0,1);
                glutcpp::pravougaonik_z(radius,height/2);
                glutcpp::translate(0,0,height+0.2);
                glutcpp::pravougaonik_z(radius,height/2);
            glutcpp::pop();
        }

    glutcpp::pop();
    }

    static void arena (int dimenzija, std::vector<Prepreka *> & prepreke)
    {
        podloga(dimenzija);

        ivica(dimenzija*2, prepreke);


    }

    static void kutija(int dimenzija, int x, int z)
    {
        glutcpp::color(0.6, 0.5, 0.2, 1);

        glutcpp::push();
        glutcpp::translate(Tacka(x, dimenzija/2, z));
        glutcpp::cube(dimenzija);
        glutcpp::pop();
    }

private:

    static void podloga(int dimenzija)
    {
        glutcpp::color(0.2, 0.2, 0.2, 1.0);
        glutcpp::push();
        glutcpp::translate(Tacka(0, -1, 0));
        glutcpp::pravougaonik(Tacka(-dimenzija, 0, -dimenzija), Tacka(dimenzija, 0, -dimenzija),
                              Tacka(dimenzija, 0, dimenzija), Tacka(-dimenzija, 0, dimenzija));
        glutcpp::pop();
        glutcpp::grid(dimenzija, 20, 0,0.5,0);
    }

    static void ivica(int dimenzija, std::vector<Prepreka *> & prepreke)
    {

        int visina = 100;
        int sirina = 20;

        prepreke.push_back(new Prepreka(dimenzija, visina, sirina, Tacka(0, 0, dimenzija/2+sirina/2), 0.3, 0.3, 0.8));
        prepreke.push_back(new Prepreka(dimenzija, visina, sirina, Tacka(0, 0, -(dimenzija/2+sirina/2)), 0.3, 0.3, 0.8));
        prepreke.push_back(new Prepreka(sirina, visina, dimenzija, Tacka(dimenzija/2+sirina/2, 0, 0), 0.3, 0.3, 0.8));
        prepreke.push_back(new Prepreka(sirina, visina, dimenzija, Tacka(-(dimenzija/2+sirina/2),0, 0), 0.3, 0.3, 0.8));

        for (auto p : prepreke) {
            p->draw();
        }

//        glutcpp::kvadar(Tacka(-dimenzija, 0, -dimenzija-sirina), Tacka(-dimenzija, visina, -dimenzija-sirina),
//                        Tacka(-dimenzija, visina, dimenzija+sirina), Tacka(-dimenzija, 0, dimenzija+sirina),
//                        Tacka(-dimenzija-sirina, 0, -dimenzija-sirina), Tacka(-dimenzija-sirina, visina, -dimenzija-sirina),
//                        Tacka(-dimenzija-sirina, visina, dimenzija+sirina), Tacka(-dimenzija-sirina, 0, dimenzija+sirina));

//        glutcpp::kvadar(Tacka(dimenzija, 0, -dimenzija-sirina), Tacka(dimenzija, visina, -dimenzija-sirina),
//                        Tacka(dimenzija, visina, dimenzija+sirina), Tacka(dimenzija, 0, dimenzija+sirina),
//                        Tacka(dimenzija+sirina, 0, -dimenzija-sirina), Tacka(dimenzija+sirina, visina, -dimenzija-sirina),
//                        Tacka(dimenzija+sirina, visina, dimenzija+sirina), Tacka(dimenzija+sirina, 0, dimenzija+sirina));

//        glutcpp::kvadar(Tacka(-dimenzija, 0, -dimenzija), Tacka(-dimenzija, visina, -dimenzija),
//                        Tacka(dimenzija, visina, -dimenzija), Tacka(dimenzija, 0, -dimenzija),
//                        Tacka(-dimenzija, 0, -dimenzija-sirina), Tacka(-dimenzija, visina, -dimenzija-sirina),
//                        Tacka(dimenzija, visina, -dimenzija-sirina), Tacka(dimenzija, 0, -dimenzija-sirina));

//        glutcpp::kvadar(Tacka(-dimenzija, 0, dimenzija), Tacka(-dimenzija, visina, dimenzija),
//                        Tacka(dimenzija, visina, dimenzija), Tacka(dimenzija, 0, dimenzija),
//                        Tacka(-dimenzija, 0, dimenzija+sirina), Tacka(-dimenzija, visina, dimenzija+sirina),
//                        Tacka(dimenzija, visina, dimenzija+sirina), Tacka(dimenzija, 0, dimenzija+sirina));
    }

};


#endif // DELOVI_H
