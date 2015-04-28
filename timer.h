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


/* Klasa koja sluzi za rad sa timerom/animacijom i izracunavanja */


#ifndef TIMER_H
#define TIMER_H


/* Broj milisekundi pauze izmedju 2 racunanja animacije */
//#define TIMER 50

/* Broj izvrsavanja animacije za 1 sekund */
#define SECOND 1000.0/50


class Timer
{
public:

    Timer(){}
    ~Timer(){}

    void setMs(int ms)
    {
        _ms=ms;
        _second=1000.0/_ms;
    }

    /* Funkcija za timer i izracunavanje */
    void timer(int id) const;

private:
    int _ms;
    float _second;
};


class Timer_init
{
public:

    static void run(int ms)
    {
        timer->setMs(ms);
        glutTimerFunc(ms,onTimer,0);
    }

private:

    Timer_init(){}
    ~Timer_init(){}

    /* glut input funkcija za rad sa vremenom koja prima milisekunde */
    static void onTimer(int id)
    {
        timer->timer(id);
    }

    static Timer * timer;
};
Timer * Timer_init::timer=new Timer();


#endif // TIMER_H
