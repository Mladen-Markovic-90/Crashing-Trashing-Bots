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


#ifndef ANIMATION_TIMER_H
#define ANIMATION_TIMER_H


/* ukljucujemo potrebna zaglavlja */
#include <vector>
#include "glutcpp/glutAnimationTimer.h"
#include "robot.h"
#include "prepreka.h"
#include "animationStatus.h"


/* klasa za rad sa timerom i operacije animacije */
class animationTimer : public glutAnimationTimer
{
public:
    /* konstruktor i destruktor */
    animationTimer(int ms,std::vector<Robot *> & r,std::vector<Prepreka *> & p,animationStatus & s):_ms(ms),roboti(r),prepreke(p),status(s){}
    ~animationTimer(){}

    /* getter za milisekunde */
    virtual int getMs() const
    {
        return _ms;
    }

    /* getter za tikove po sekundi */
    virtual float getTicksPerSecond() const
    {
        return 1000.0/_ms;
    }

    /* Funkcija za timer i izracunavanje */
    virtual void timer(int id) const;

private:
    /* promenljiva koja cuva milisekunde za timer */
    int _ms;

    /* vektor koji cuva robotere */
    std::vector<Robot *> & roboti;

    std::vector<Prepreka *> & prepreke;

    /* promenljiva koja cuva status prikaza */
    animationStatus & status;
};


#include "animationTimer.cpp"


#endif // ANIMATION_TIMER_H
