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


#ifndef GLUT_RESHAPE_LISTENER_H
#define GLUT_RESHAPE_LISTENER_H


/* ukljucujemo potrebna zaglavlja */
#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface za display */
class glutReshapeListener
{
public:
    /* konstruktor i virtualni destruktor */
    glutReshapeListener(){}
    virtual ~glutReshapeListener(){}

    /* Obrada prikaza za prozor u zavisnosti od modusa */
    virtual void reshape(int width,int height)
    {width=width;height=height;}

    /* pozivanje obrade ponovo */
    virtual void reshape(){}

    /* getter za sirinu i visinu prozora */
    virtual int getWindowWidth() const {return 0;}
    virtual int getWindowHeight() const {return 0;}
};


/* klasa za postavljanje osluskivaca za promenu velicine prozora u glutu */
class glutReshapeListenerInit
{
public:
    /* pokretanje glut osluskivac za  promenu velicine prozora */
    static void run(glutReshapeListener * rl)
    {
        delete reshapeListener;
        reshapeListener=rl;
        glutReshapeFunc(onReshape);
    }

    /* ukoliko je potrebno, moze da se uzme pokazivac na motionListener */
    static glutReshapeListener * getReshapeListener()
    {
        return reshapeListener;
    }

private:
    /* konstruktor i destruktor */
    glutReshapeListenerInit(){}
    ~glutReshapeListenerInit(){}

    /* glut input funkcija za podesavanje prozora */
    static void onReshape(int width,int height)
    {
        reshapeListener->reshape(width,height);
    }

    /* promenljiva koja cuva osluskivac za promenu velicine prozora */
    static glutReshapeListener * reshapeListener;
};
/* inicijalizacija statickog pokazivaca na null */
glutReshapeListener * glutReshapeListenerInit::reshapeListener=nullptr;


#endif // GLUT_RESHAPE_LISTENER_H
