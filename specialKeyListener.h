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


#ifndef SPECIAL_KEY_LISTENER_H
#define SPECIAL_KEY_LISTENER_H


/* ukljucujemo potrebna zaglavlja */
#include "glutcpp/glutSpecialKeyListener.h"
#include "robot.h"
#include <vector>


/* klasa za rad sa specijalnim karakterima sa tastature */
class SpecialKeyListener : public glutSpecialKeyListener
{
public:
    /* konstruktor i destruktor */
    SpecialKeyListener(std::vector<Robot *> & r,int & m):roboti(r),modus(m){}
    ~SpecialKeyListener(){}

    /* postavljanje flagova ili radnja za specijalne karaktere koja su stisnuta na tastaturi */
    void keyDown(int key,int x,int y) const;

    /* skidanje flagova za specijalne karaktere koja su stisnuta na tastaturi */
    void keyUp(int key,int x,int y) const;

private:
    int & modus;
    /* vektor koji cuva robotere */
    std::vector<Robot *> & roboti;
};


#include "specialKeyListener.cpp"


#endif // SPECIAL_KEY_LISTENER_H
