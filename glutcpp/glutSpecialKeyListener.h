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


#ifndef GLUT_SPECIAL_KEY_LISTENER_H
#define GLUT_SPECIAL_KEY_LISTENER_H


/* ukljucujemo potrebna zaglavlja */
#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface za osluskivac specijalnih karaktera */
class glutSpecialKeyListener
{
public:
    /* konstruktor i virtualni destruktor */
    glutSpecialKeyListener(){}
    virtual ~glutSpecialKeyListener(){}

    /* radnja za stisnute specijalne karatere */
    virtual void keyDown(int key,int x,int y) const {key=key;x=x;y=y;}

    /* radnja za otpustene specijalne karaktere */
    virtual void keyUp(int key,int x,int y) const {key=key;x=x;y=y;}
};


/* klasa za postavljanje osluskivaca za specijalne karaktere u glutu */
class glutSpecialKeyListenerInit
{
public:
    /* pokretanje glut osluskivac za specijalne karaktere */
    static void run(glutSpecialKeyListener * skl)
    {
        /* brisemo stari special key listener, da ne bi bilo curenje memorije */
        delete specialKeyListener;

        /* upisemo novi special key listener i pokrecemo ga */
        specialKeyListener=skl;
        glutSpecialFunc(keyDown);
        glutSpecialUpFunc(keyUp);
    }

private:
    /* konstruktor i destruktor */
    glutSpecialKeyListenerInit(){}
    ~glutSpecialKeyListenerInit(){}

    /* glut input funkcija za citanje specijalnih stisnutih karaktera sa tastature */
    static void keyDown(int key, int x, int y) {specialKeyListener->keyDown(key,x,y);}

    /* glut input funkcija za citanje specijalnih otpustenih karaktera sa tastature */
    static void keyUp(int key, int x, int y) {specialKeyListener->keyUp(key,x,y);}

    /* promenljiva koja cuva osluskivac za specijalne karakter */
    static glutSpecialKeyListener * specialKeyListener;
};
/* inicijalizacija statickog pokazivaca na null */
glutSpecialKeyListener * glutSpecialKeyListenerInit::specialKeyListener=nullptr;


#endif // GLUT_SPECIAL_KEY_LISTENER_H
