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


#ifndef DISPLAY_H
#define DISPLAY_H


#include "glutcpp/glutDisplay.h"


#define NO_SWAP 0
#define SWAP 1


/* klasa koja ima sadrzaj prozora */
class Display : public glutDisplay
{
public:
    /* konstruktor i destruktor */
    Display(std::vector<Robot *> & r,int & m) : roboti(r) , modus(m) {}
    ~Display(){}

    /* prikazuje sadrzaj prozora */
    void show();

    /* prikazuje meni */
    void meni();

    /* prikazuje meni->start */
    void start();

    /* prikazuje arena */
    void arena();

    /* prikazuje sadrzaj testiranja mladen */
    void test_mladen();

private:
    /* parametri kamere */
    float camera_ugao=0;
    float camera_indikator=NO_SWAP;
    Tacka cam_position=Tacka(0,0,0);
    int cam_dist = 20;

    /* funkcija za namestanje kamere */
    void adjust_camera();

    int & modus;

    std::vector<Robot *> & roboti;
};


#include "display.cpp"


#endif // DISPLAY_H
