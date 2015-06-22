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


#ifndef GLUT_ANIMATION_TIMER_H
#define GLUT_ANIMATION_TIMER_H


/* ukljucujemo potrebna zaglavlja */
#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface za animacije */
class glutAnimationTimer
{
public:
    /* konstruktor i virtualni destruktor */
    glutAnimationTimer(){}
    virtual ~glutAnimationTimer(){}

    /* getter za milisekunde */
    virtual int getMs() const {return 0;}

    /* getter za tikove po sekundi */
    virtual float getTicksPerSecond() const {return 0;}

    /* Funkcija za timer i izracunavanje */
    virtual void timer(int id) const {id=id;}
};


/* klasa za postavljanje timera za animacije */
class glutAnimationTimerInit
{
public:
    /* pokretanje animacije za glut */
    static void run(glutAnimationTimer * at)
    {
        /* brisemo stari animation timer, da ne bi bilo curenje memorije */
        delete animationTimer;

        /* upisemo novi animation timer i pokrecemo ga */
        animationTimer=at;
        glutTimerFunc(at->getMs(),onTimer,0);
    }

    /* getter za AnimationTimer */
    static glutAnimationTimer * getAnimationTimer() {return animationTimer;}

private:
    /* konstruktor i destruktor */
    glutAnimationTimerInit(){}
    ~glutAnimationTimerInit(){}

    /* glut input funkcija za rad sa vremenom koja prima milisekunde */
    static void onTimer(int id)
    {
        /* pokrecemo animation timer i pokrecemo ga ponovo za neki broj mili sekundi */
        animationTimer->timer(id);
        glutTimerFunc(animationTimer->getMs(),onTimer,0);
    }

    /* promenljiva koja cuva timer za animacije */
    static glutAnimationTimer * animationTimer;
};
/* inicijalizacija statickog pokazivaca na null */
glutAnimationTimer * glutAnimationTimerInit::animationTimer=nullptr;


#endif // GLUT_ANIMATION_TIMER_H
