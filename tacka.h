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


#ifndef TACKA
#define TACKA


class Tacka
{
public:
    Tacka();
    Tacka(const float & x,const float & y,const float & z);
    Tacka(const Tacka & t); // sta ce ti kopi konstruktor?

    float get_x() const;
    float get_y() const;
    float get_z() const;
    void set_x(const float x);
    void set_y(const float y);
    void set_z(const float z);
    void add(const float x,const float y,const float z);
    void add(Tacka t);


private:
    float _x;
    float _y;
    float _z;
};


#endif // TACKA
