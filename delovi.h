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
};


#endif // DELOVI_H
