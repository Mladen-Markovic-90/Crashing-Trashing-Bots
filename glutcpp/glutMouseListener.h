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


#ifndef GLUT_MOUSE_LISTENER_H
#define GLUT_MOUSE_LISTENER_H


/* ukljucujemo potrebna zaglavlja */
#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface osluskivac za dugmad misa */
class glutMouseListener
{
public:
    /* konstruktor i virtualni destruktor */
    glutMouseListener(){}
    virtual ~glutMouseListener(){}

    /* Desavanje na osnovu klika misa */
    void mouse(int button,int state,int x,int y) const
    {button=button;state=state;x=x;y=y;}
};


/* klasa za postavljanje osluskivaca za dugmad misa u glutu */
class glutMouseListenerInit
{
public:
    /* pokretanje glut osluskivac za poziciju misa */
    static void run(glutMouseListener * ml)
    {
        delete mouseListener;
        mouseListener=ml;
        glutMouseFunc(onMouse);
    }

    /* ukoliko je potrebno, moze da se uzme pokazivac na mouseListener */
    static glutMouseListener * getMouseListener()
    {
        return mouseListener;
    }

private:
    /* promenljiva koja cuva osluskivac za dugmad misa */
    static glutMouseListener * mouseListener;

    /* konstruktor i destruktor */
    glutMouseListenerInit(){}
    ~glutMouseListenerInit(){}

    /* glut input funkcija za citanje stanje dugmad misa */
    static void onMouse(int button,int state,int x,int y)
    {
        mouseListener->mouse(button,state,x,y);
    }
};
/* inicijalizacija statickog pokazivaca na null */
glutMouseListener * glutMouseListenerInit::mouseListener=nullptr;


#endif // GLUT_MOUSE_LISTENER_H
