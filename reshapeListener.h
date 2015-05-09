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


#ifndef RESHAPE_LISTENER_H
#define RESHAPE_LISTENER_H


/* ukljucujemo potrebna zaglavlja */
#include "glutcpp/glutReshapeListener.h"


/* klasa za rad sa prozorom */
class reshapeListener : public glutReshapeListener
{
public:
    /* konstruktor i destruktor */
    reshapeListener(int width,int height,int & m)
        : windowWidth(width) , windowHeight(height) , modus(m)
    {}
    ~reshapeListener(){}

    /* Obrada prikaza za prozor u zavisnosti od modusa */
    virtual void reshape(int width,int height);

    /* getter za sirinu i visinu prozora */
    virtual int getWindowWidth() const {return windowWidth;}
    virtual int getWindowHeight() const {return windowHeight;}

private:
    int & modus;

    /* promenljive za sirinu i visinu prozora */
    int windowWidth;
    int windowHeight;
};


#include "reshapeListener.cpp"


#endif // RESHAPE_LISTENER_H
