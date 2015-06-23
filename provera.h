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

#ifndef PROVERA_H
#define PROVERA_H

#include "glutcpp/tacka.h"
#include "vektor3d.h"
#include <cmath>

class provera
{
public:
    // povrsina za 2D
    static double povrsina(Tacka a,Tacka b,Tacka c)
    {
        Tacka vec1=Vektor3D::vektor(a,b);
        Tacka vec2=Vektor3D::vektor(b,c);
        vec1.set_y(0);
        vec2.set_y(0);
        return Vektor3D::duzina(Vektor3D::vektorskiProizvod(vec1,vec2));
    }

    // Racuna koordinate u svetskom koordinatnom sistemu
    static Tacka position(Tacka t,Tacka center,float ugao)
    {
        Tacka tmp=Tacka(0,0,0);
        double pi=(M_PI*1.0);
        tmp.set_x(t.get_x()*std::cos((-ugao/180.0)*pi)+t.get_z()*std::sin((-ugao/180.0)*pi));
        tmp.set_z(t.get_x()*std::sin((ugao/180.0)*pi)+t.get_z()*std::cos((-ugao/180.0)*pi));
        tmp.add(center);
        return tmp;
    }



private:
    provera();
    ~provera();

};

#endif // PROVERA_H

