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


#ifndef GLUT_MOTION_LISTENER_H
#define GLUT_MOTION_LISTENER_H


/* ukljucujemo potrebna zaglavlja */
#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface za osluskivac pozicije misa */
class glutMotionListener
{
public:
    /* konstruktor i virtualni destruktor */
    glutMotionListener(){}
    virtual ~glutMotionListener(){}

    /* Rad na osnovu pozicije misa */
    virtual void motion(int x, int y) const {x=x;y=y;}
};


/* klasa za postavljanje osluskivaca za poziciju misa u glutu */
class glutMotionListenerInit
{
public:
    /* pokretanje glut osluskivac za poziciju misa */
    static void run(glutMotionListener * ml)
    {
        delete motionListener;
        motionListener=ml;
        glutMotionFunc(onMotion);
    }

    /* ukoliko je potrebno, moze da se uzme pokazivac na motionListener */
    static glutMotionListener * getMotionListener()
    {
        return motionListener;
    }

private:
    /* promenljiva koja cuva osluskivac za poziciju misa */
    static glutMotionListener * motionListener;

    /* konstruktor i destruktor */
    glutMotionListenerInit(){}
    ~glutMotionListenerInit(){}

    /* glut input funkcija za citanje pozicije misa */
    static void onMotion(int x,int y)
    {
        motionListener->motion(x,y);
    }
};
/* inicijalizacija statickog pokazivaca na null */
glutMotionListener * glutMotionListenerInit::motionListener=nullptr;


#endif // GLUT_MOTION_LISTENER_H
