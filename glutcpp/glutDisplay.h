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


#ifndef GLUT_DISPLAY_H
#define GLUT_DISPLAY_H


/* ukljucujemo potrebna zaglavlja */
#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface za display */
class glutDisplay
{
public:
    /* konstruktor i virtualni destruktor */
    glutDisplay(){}
    virtual ~glutDisplay(){}

    /* prikazuje sadrzaj prozora */
    virtual void show(){}
};


/* klasa za inicijalizaciju display funkcije u glutu */
class glutDisplayInit
{
public:
    /* pokretanje displaya za glut */
    static void run(glutDisplay * d)
    {
        delete display;
        display=d;
        glutDisplayFunc(onDisplay);
    }

    /* ukoliko je potrebno, moze da se uzme pokazivac na Display */
    static glutDisplay * getDisplay()
    {
        return display;
    }

private:
    /* promenljiva koja cuva trenutni display */
    static glutDisplay * display;

    /* konstruktor i destruktor */
    glutDisplayInit(){}
    ~glutDisplayInit(){}

    /* glut input funkcija za crtanje */
    static void onDisplay(void)
    {
        display->show();
    }
};
/* inicijalizacija statickog pokazivaca na null */
glutDisplay * glutDisplayInit::display=nullptr;


#endif // GLUT_DISPLAY_H
