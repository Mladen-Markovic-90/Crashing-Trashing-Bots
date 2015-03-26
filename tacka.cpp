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


/* Klasa koja pamti tacke i sluzi za rad sa tackama */


/* Ukljucivanje potrebnih zaglavlja */
#include "tacka.h"


/* Konstruktor bez argumenata */
Tacka::Tacka() {}


/* Konstruktor koji prima koordinate */
Tacka::Tacka(const float & x,const float & y,const float & z)
{
    this->_x=x;
    this->_y=y;
    this->_z=z;
}


/* Kopi konstruktor */
Tacka::Tacka(const Tacka & t)
{
    this->_x=t._x;
    this->_y=t._y;
    this->_z=t._z;
}


/* Getter za koordinatu x */
float Tacka::get_x() const
{
    return this->_x;
}


/* Getter za koordinatu y */
float Tacka::get_y() const
{
    return this->_y;
}


/* Getter za koordinatu z */
float Tacka::get_z() const
{
    return this->_z;
}


/* Setter za koordinatu x */
void Tacka::set_x(const float x)
{
    this->_x=x;
}


/* Setter za koordinatu y */
void Tacka::set_y(const float y)
{
    this->_y=y;
}


/* Setter za koordinatu z */
void Tacka::set_z(const float z)
{
    this->_z=z;
}


/* Sabiranje Tacke sa koordinatama */
void Tacka::add(const float x,const float y,const float z)
{
    this->_x+=x;
    this->_y+=y;
    this->_z+=z;
}


/* Sabiranje Tacke sa Tackom */
void Tacka::add(Tacka t)
{
    this->_x+=t.get_x();
    this->_y=t.get_y();
    this->_z=t.get_z();
}

/* operacije "u mestu" */
Tacka& Tacka::operator+= (const Tacka& t2)
{
    this->set_x(this->get_x() + t2.get_x());
    this->set_y(this->get_y() + t2.get_y());
    this->set_z(this->get_z() + t2.get_z());    

    return *this;
}

Tacka& Tacka::operator-= (const Tacka& t2)
{
    this->set_x(this->get_x() - t2.get_x());
    this->set_y(this->get_y() - t2.get_y());
    this->set_z(this->get_z() - t2.get_z());    

    return *this;
}


Tacka& Tacka::operator*= (float k)
{
    this->set_x(this->get_x() * k);
    this->set_y(this->get_y() * k);
    this->set_z(this->get_z() * k);    

    return *this;
}

Tacka& Tacka::operator/= (float k)
{
    this->set_x(this->get_x() / k);
    this->set_y(this->get_y() / k);
    this->set_z(this->get_z() / k);    

    return *this;
}


