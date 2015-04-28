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


/* Rad sa klikom misa */


#ifndef MOUSE_H
#define MOUSE_H


class Mouse
{
public:
    Mouse(){}
    ~Mouse(){}

    /* Desavanje na osnovu klika misa */
    void mouse(int button,int state,int x,int y) const;
};


class Mouse_init
{
public:


    static void run()
    {
        glutMouseFunc(onMouse);
    }

private:
    Mouse_init(){}
    ~Mouse_init(){}


    /* glut input funkcija za citanje stanje dugmad misa */
    static void onMouse(int button,int state,int x,int y)
    {
        mouse->mouse(button,state,x,y);
    }

    static Mouse * mouse;
};
Mouse * Mouse_init::mouse=new Mouse();

#endif // MOUSE_H
