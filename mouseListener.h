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


#ifndef MOUSE_LISTENER_H
#define MOUSE_LISTENER_H


/* ukljucujemo potrebna zaglavlja */
#include "glutcpp/glutMouseListener.h"


/* klasa za rad sa klikom misa */
class mouseListener : public glutMouseListener
{
public:
    /* konstruktor i destruktor */
    mouseListener(){}
    ~mouseListener(){}

    /* Desavanje na osnovu klika misa */
    void mouse(int button,int state,int x,int y) const;
};


#endif // MOUSE_LISTENER_H
