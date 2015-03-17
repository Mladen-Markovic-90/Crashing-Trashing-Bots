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


#include "reshape.h"
#include "glut.h"


void Reshape::reshape(int width, int height)
{

}


void Reshape::set_height(int height)
{
    this->height=height;
}

void Reshape::set_width(int width)
{
    this->width=width;
}


int Reshape::get_height()
{
    return this->height;
}


int Reshape::get_width()
{
    return this->width;
}
