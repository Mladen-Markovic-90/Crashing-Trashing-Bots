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


/* Rad sa specijalnim karakterima sa tastature */


#ifndef SPECIAL_KEYS_H
#define SPECIAL_KEYS_H


class Special_keys
{
public:
    Special_keys(){}
    ~Special_keys(){}

    /* postavljanje flagova ili radnja za specijalne karaktere koja su stisnuta na tastaturi */
    void setKey(int key,int x,int y) const;

    /* skidanje flagova za specijalne karaktere koja su stisnuta na tastaturi */
    void unsetKey(int key,int x,int y) const;
};



class Special_keys_init
{
public:


    static void run()
    {
        glutSpecialFunc(setSpecKey);
        glutSpecialUpFunc(unsetSpecKey);
    }

private:
    Special_keys_init(){}
    ~Special_keys_init(){}
    /* glut input funkcija za citanje specijalnih stisnutih karaktera sa tastature */
    static void setSpecKey(int key, int x, int y)
    {
        special_keys->setKey(key,x,y);
    }

    /* glut input funkcija za citanje specijalnih otpustenih karaktera sa tastature */
    static void unsetSpecKey(int key, int x, int y)
    {
        special_keys->unsetKey(key,x,y);
    }

    static Special_keys * special_keys;
};
Special_keys * Special_keys_init::special_keys=new Special_keys();


#endif // SPECIAL_KEYS_H
