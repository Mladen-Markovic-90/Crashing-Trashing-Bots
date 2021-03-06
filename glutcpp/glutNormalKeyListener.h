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


#ifndef GLUT_NORMAL_KEY_LISTENER_H
#define GLUT_NORMAL_KEY_LISTENER_H


/* ukljucujemo potrebna zaglavlja */
#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface za osluskivac obicnih karaktera */
class glutNormalKeyListener
{
public:
    /* konstruktor i virtualni destruktor */
    glutNormalKeyListener(){}
    virtual ~glutNormalKeyListener(){}

    /* radnja za stisnute obicne karatere */
    virtual void keyDown(unsigned char normalKey,int x,int y) const {normalKey=normalKey;x=x;y=y;}

    /* radnja za otpustene obicne karaktere */
    virtual void keyUp(unsigned char normalKey,int x,int y) const {normalKey=normalKey;x=x;y=y;}
};


/* klasa za postavljanje osluskivaca za obicne karaktere u glutu */
class glutNormalKeyListenerInit
{
public:
    /* pokretanje glut osluskivac za obicne karaktere */
    static void run(glutNormalKeyListener * nkl)
    {
        /* brisemo stari normal key listener, da ne bi bilo curenje memorije */
        delete normalKeyListener;

        /* upisemo novi normal key listener i pokrecemo ga */
        normalKeyListener=nkl;
        glutKeyboardFunc(keyDown);
        glutKeyboardUpFunc(keyUp);
    }

    /* ukoliko je potrebno, moze da se uzme pokazivac na normalKeyListener */
    static glutNormalKeyListener * getNormalKeyListener() {return normalKeyListener;}

private:
    /* promenljiva koja cuva osluskivac za obicnih karakter */
    static glutNormalKeyListener * normalKeyListener;

    /* konstruktor i destruktor */
    glutNormalKeyListenerInit(){}
    ~glutNormalKeyListenerInit(){}

    /* glut input funkcija za citanje stisnutih obicnih karaktera sa tastature */
    static void keyDown(unsigned char normalKey, int x, int y) {normalKeyListener->keyDown(normalKey,x,y);}

    /* glut input funkcija za citanje otpustenih karaktera sa tastature */
    static void keyUp(unsigned char normalKey, int x, int y) {normalKeyListener->keyUp(normalKey,x,y);}
};
/* inicijalizacija statickog pokazivaca na null */
glutNormalKeyListener * glutNormalKeyListenerInit::normalKeyListener=nullptr;


#endif // GLUT_NORMAL_KEY_LISTENER_H
