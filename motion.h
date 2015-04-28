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


/* Rad pozicijom misa */


#ifndef MOTION_H
#define MOTION_H


class Motion
{
public:
    Motion(){}
    ~Motion(){}

    /* Rad na osnovu pozicije misa */
    void motion(int x, int y) const;
};



class Motion_init
{
public:


    static void run()
    {
        glutMotionFunc(onMotion);
    }

private:
    Motion_init(){}
    ~Motion_init(){}


    /* glut input funkcija za citanje pozicije misa */
    static void onMotion(int x,int y)
    {
        motion->motion(x,y);
    }

    static Motion * motion;
};
Motion * Motion_init::motion=new Motion();


#endif // MOTION_H
