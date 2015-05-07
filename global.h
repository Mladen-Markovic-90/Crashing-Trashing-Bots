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


/* biblioteka koja je globalna i ukljucuje sva zaglavlja i globalne promenljive i globalne konstante */


#ifndef GLOBAL_H
#define GLOBAL_H


/* PI define za Windows */
#ifndef M_PI
#define M_PI 3.14159265359
#endif
#ifndef M_PI_2
#define M_PI_2 M_PI/2.0
#endif


/* definicije za trenutni prozor */
#define MODUS_MENI 0
#define MODUS_START 1
#define MODUS_ARENA 2
#define MODUS_3 3
#define MODUS_4 4
#define MODUS_5 5
#define MODUS_6 6
#define MODUS_TEST_MLADEN 7


/* trenutni prozor */
//int modus=MODUS_ARENA;
int modus=MODUS_TEST_MLADEN;




/* Ukljucujemo sve potrebna zaglavlja */
#include "glutcpp/glutcpp.h"
#include "motionListener.h"
#include "mouseListener.h"
#include "reshapeListener.h"
#include "special_keys.h"
#include "glutcpp/tacka.h"
#include "animationTimer.h"
#include "robot.h"
#include <vector>
std::vector<Robot *> roboti;
#include "normalKeyListener.h"
#include "display.h"


/* specijalne globalne promenljive */


/* sledi nekoliko funkcija za ulaz u glutXXXXfunc() */


#endif // GLOBAL_H
