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


/* klasa koja sluzi za prikaz sadrzaja prozora */


#ifndef DISPLAY_H
#define DISPLAY_H


#define NO_SWAP 0
#define SWAP 1


class Display
{
public:

    Display(){}
    ~Display(){}
    /* prikazuje sadrzaj prozora */
    void show();

    /* prikazuje meni */
    void meni();

    /* prikazuje meni->start */
    void start();

    /* prikazuje arena */
    void arena();

    /* prikazuje sadrzaj testiranja mladen */
    void test_mladen();


private:

    /* parametri kamere */
    float camera_ugao=0;
    float camera_indikator=NO_SWAP;
    Tacka cam_position=Tacka(0,0,0);
    int cam_dist = 20;

    /* funkcija za namestanje kamere */
    void adjust_camera();
};


class Display_init
{
public:

    /* inicijalizacija za display */
    static void run()
    {
        glutDisplayFunc(onDisplay);
    }

private:

    Display_init(){}
    ~Display_init(){}

    /* glut input funkcija za crtanje */
    static void onDisplay(void)
    {
        display->show();
    }

    static Display * display;
};
Display * Display_init::display=new Display();

/*
class Display_init
{
public:
    static void init(std::vector<Robot *> & r)
    {
        d->setRobote(r);
        glutDisplayFunc(onDisplay);
    }

    static Display * get()
    {
        return Display_init::d;
    }

private:
    static void onDisplay(void)
    {
        d->show();
    }

    static Display * d;
};
Display * Display_init::d=new Display();*/


#endif // DISPLAY_H
