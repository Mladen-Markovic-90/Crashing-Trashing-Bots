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


/* ukljucivanje potrebnih zaglavlja */
#include <iostream>
#include "global.h"
#include <cmath>
#include <cassert> // za debagovanje


using namespace std;


/* prikazuje sadrzaj prozora */
void Display::show(void)
{
    if(modus==MODUS_MENI)
	Display::meni();
    else if(modus==MODUS_START)
	Display::start();
    else if(modus==MODUS_ARENA)
	Display::arena();
    else if(modus==MODUS_TEST_MLADEN)
	Display::test_mladen();
}


/* prikazuje meni */
void Display::meni()
{
    glut::light(GL_OFF);
    glut::modelView2D();

    glut::color(1,0,0,1);
    glut::pravougaonik(Tacka(1,1,0),Tacka(1,-1,0),Tacka(0,-1,0),Tacka(0,1,0));

    glut::color(1,1,1,1);
    glut::text(0.5,0.5,"Test");
    glut::text(0,0,"Test");
    glut::swapBuffers();
}


/* prikazuje meni->start */
void Display::start()
{

}


/* prikazuje arena */
void Display::arena()
{
    //this->ugao+=0.1;
    glut::light(GL_ON);

    glut::modelView3D(0,0,200);

    glut::color(0,1.0,0,1.0);
    glut::lightPosition(0,0,0,1);
    //    glut::lookAt(100*std::sin((float)ugao/180*PII), 100, 100*std::cos((float)ugao/180*PII) , 0, 0, 0);

    adjust_camera();

    glut::grid(200, 5, 1.0f, 0.0f, 0.0f);

    for(Robot * item : roboti)
	item->draw();

    for(Robot * item : roboti)
        item->display3D(45,window_width,window_height,1,1000);


    glut::swapBuffers();
    cout << "swapovao" << endl;
}


/* prikazuje sadrzaj testiranja mladen */
void Display::test_mladen()
{

    //this->ugao+=0.1;
    glut::light(GL_ON);

    glut::lightPosition(0,0,0,1);
    //glut::modelView3D(0,200,400);
    //glut::modelView3D(0,100,200);
    glut::modelView3D(0,0,200);

    glut::rotate(90,1,0,0);
    glut::rotate(90,0,1,0);
    //glut::rotate(this->ugao,0,1,0);

    //glut::grid(200, 5, 1.0f, 0.0f, 0.0f);


    for(Robot * item : roboti)
        item->draw();

    for(Robot * item : roboti)
    {
        glut::translate(item->getFront());
        glut::translate(0,20,0);
        glut::color(1,0,0,1);
        glut::cube(10);
    }
   // model_1();


    for(Robot * item : roboti)
        item->display3D(45,window_width,window_height,1,1000);
    glut::swapBuffers();
}




/* namestanje kamere za prikaz */
////////////////////////////////////
/// TODO: NAPRAVITI SPORU KAMERU ///
////////////////////////////////////
void Display::adjust_camera()
{
    cout << "ulazim u kamera metodu" << endl;
    Tacka oko(0,0,0);
    Tacka fokus(0,0,0);

    //da prikazuje iza ledja    
    if (roboti.size() == 1) {
	Robot *robot = roboti.back();
	assert(robot);
	fokus = robot->getPos();


	//nemam pojma zasto moram da dodam PI/2, nastelao sam ga
	oko.set_x(cam_dist * std::cos((float)robot->getUgao()/180*M_PI + M_PI_2) + fokus.get_x());
	oko.set_y(cam_dist);
	oko.set_z(cam_dist * std::sin((float)robot->getUgao()/180*M_PI + M_PI_2)  + fokus.get_z());
    }

    //TODO: specijalno za dva, mozda dodati posebno za vise ako bude potrebno
    if (roboti.size() >= 2) {
	Tacka prvi = roboti[0]->getPos();
	Tacka drugi = roboti[1]->getPos();
    	Tacka sredina = (prvi + drugi) / 2.0f;
	fokus = sredina;

	// projekcija kamere na xz ravan
	float dx = prvi.get_x() - sredina.get_x();
	float dz = prvi.get_z() - sredina.get_z();

	//imamo dve pozicije kandidate
	Tacka podnozje1 = sredina - Tacka(dz, 0, -dx);
	Tacka podnozje2 = sredina + Tacka(dz, 0, -dx);

	//biramo onu koja je dalja od sredine, kako bi gledala ka sredini (norma vektora)
	Tacka podnozje = podnozje1.norm() > podnozje2.norm() ? podnozje1 : podnozje2;

	oko.set_x(podnozje.get_x());
	oko.set_y(0.7 * prvi.distance(drugi)); //konstanta je nasumicna, kako mi se svidi
	oko.set_z(podnozje.get_z());
    }
    
    cout << oko.get_x() << " " << oko.get_y() << "" << oko.get_z() << endl;
    glut::lookAt(oko, fokus);
    //    cout <<"mkanp" << endl;
    
}
