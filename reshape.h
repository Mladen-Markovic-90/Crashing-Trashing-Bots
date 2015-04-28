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


/* Rad sa prozorom */


#ifndef RESHAPE_H
#define RESHAPE_H


class Reshape
{
public:
    Reshape(){}
    ~Reshape(){}

    /* Obrada prikaza za prozor u zavisnosti od modusa */
    void reshape(int width,int height) const;
};


class Reshape_init
{
public:


    static void run()
    {
        glutReshapeFunc(onReshape);
    }

private:
    Reshape_init(){}
    ~Reshape_init(){}

    /* glut input funkcija za podesavanje prozora */
    static void onReshape(int width,int height)
    {
        reshape->reshape(width,height);
    }

    static Reshape * reshape;
};
Reshape * Reshape_init::reshape=new Reshape();


#endif // RESHAPE_H
