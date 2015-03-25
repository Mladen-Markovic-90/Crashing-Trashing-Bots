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
#define TIMER 50

/* Broj izvrsavanja animacije za 1 sekund */
#define SECOND 1000.0/TIMER


class Timer
{
public:

    /* Funkcija za timer i izracunavanje */
    void timer(int id) const;
};


#endif // TIMER_H
