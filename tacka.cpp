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


#include "tacka.h"


Tacka::Tacka() {}


Tacka::Tacka(const float & x,const float & y,const float & z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}


Tacka::Tacka(const Tacka & t)
{
    this->x=t.x;
    this->y=t.y;
    this->z=t.z;
}


float Tacka::get_x()
{
    return this->x;
}


float Tacka::get_y()
{
    return this->y;
}


float Tacka::get_z()
{
    return this->z;
}


void Tacka::set_x(float x)
{
    this->x=x;
}


void Tacka::set_y(float y)
{
    this->y=y;
}


void Tacka::set_z(float z)
{
    this->z=z;
}
