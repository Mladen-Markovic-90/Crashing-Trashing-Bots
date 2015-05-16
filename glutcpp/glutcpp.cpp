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


/* ukljucujemo potrebna zaglavlja */
#include <GL/freeglut.h>
#include "glutcpp.h"


/* inicijalizacija freeglut */
void glutcpp::init(int argc,char ** argv,int width,int heigth,std::string name)
{
    /* inicijalizacija prozora */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB |  GLUT_DEPTH |  GLUT_DOUBLE);
    glutInitWindowSize(width,heigth);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(name.c_str());

    /* podesavanje svetla */
    GLfloat lightambient[4]={0.5f,0.5f,0.5f,1.0f};
    GLfloat lightdiffuse[4]={0.7f,0.7f,0.7f,1.0f};
    GLfloat lightspecular[4]={0.9f,0.9f,0.9f,1.0f};
    glLightfv(GL_LIGHT0,GL_AMBIENT,lightambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightdiffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,lightspecular);

    /* podesavanje providnosti */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /* postavljanje background boje */
    glClearColor(0,0,0,1);
}


/* glMainLoop() -> pokretanje glut petlje */
void glutcpp::start()
{
    glutMainLoop();
}


/* glBegin() -> zapocinjemo crtanje */
void glutcpp::begin(GLenum arg)
{
    glBegin(arg);
}


/* glEnd() -> zavrsavamo crtanje */
void glutcpp::end()
{
    glEnd();
}


/* ukljucivanje ili iskljucivanje svetla sa normalama */
void glutcpp::light(int arg)
{
    if(arg==GL_ON)
        {
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        }
    else
        {
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        glDisable(GL_NORMALIZE);
        }
}


/* boja nezavisno od svetla */
void glutcpp::color(float r, float g, float b, float a)
{
    if(glIsEnabled(GL_LIGHTING))
    {
        float colorambient[4]={r*0.8f,g*0.8f,b*0.8f,a};
        float colordiffuse[4]={r,g,b,a};
        float colorspecular[4]={0,0,0,a};/*
        float colorambient[4]={r*0.5f,g*0.5f,b*0.5f,a};
        float colordiffuse[4]={r*0.7f,g*0.7f,b*0.7f,a};
        float colorspecular[4]={r*0.9f,g*0.9f,b*0.9f,a};
        GLfloat shininess = 10;
        glMaterialf(GL_FRONT, GL_SHININESS, shininess);*/
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,colorambient);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,colordiffuse);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,colorspecular);
    }
    else
        glColor4f(r,g,b,a);
}


/* podesavanje za rad u 3D */
void glutcpp::projection3D(int width, int height, int ugao, int arg1,int arg2)
{
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(ugao, (float) width / height, arg1, arg2);
}


/* podesavanje za rad u 2D */
void glutcpp::projection2D(int width,int height)
{
    glDisable(GL_DEPTH_TEST);
    glViewport(0, 0, width, height);

    /* Brisemo podesavanje matrice da bi bili u 2D */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}


/* podesavanje za prikazivanje u 2D */
void glutcpp::modelView2D()
{
    glutcpp::clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glShadeModel(GL_SMOOTH);
}


/* podesavanje za prikazivanje u 3D */
void glutcpp::modelView3D(float x,float y,float z)
{
    glutcpp::clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x,y,z,0, 0, 0, 0, 1, 0);
    glShadeModel(GL_SMOOTH);
}


/* funkcija za namestanje kamere */
void glutcpp::lookAt(Tacka oko, Tacka fokus)
{
    gluLookAt(oko.get_x(), oko.get_y(), oko.get_z(),
	      fokus.get_x(), fokus.get_y(), fokus.get_z(), 0, 1, 0);
}


/* pozicija svetla */
void glutcpp::lightPosition(float x, float y, float z,float w)
{
    float array[4]={x,y,z,w};
    glLightfv(GL_LIGHT0,GL_POSITION,array);
}


/* tacka sa 3 koordinate i homogena koordinata */
void glutcpp::vertex(float x, float y, float z,float w)
{
    glVertex4f(x,y,z,w);
}


/* tacka sa 3 koordinate */
void glutcpp::vertex(float x, float y, float z)
{
    glVertex3f(x,y,z);
}


/* tacka koja prima tacku */
void glutcpp::vertex(Tacka t)
{
    glVertex3f(t.get_x(),t.get_y(),t.get_z());
}


/* tacka koja prima tacku i homogenu koordinatu */
void glutcpp::vertex(Tacka t, float w)
{
    glVertex4f(t.get_x(),t.get_y(),t.get_z(),w);
}


/* normala definisana sa 3 koordinate */
void glutcpp::normal(float x, float y, float z)
{
    glNormal3f(x,y,z);
}


/* normala definisana sa 3 koordinate i homogena koordinata */
void glutcpp::normal(float x, float y, float z, float w)
{
    if(w>0.001 && w<-0.001)
        glNormal3f(x/w,y/w,z/w);
    else
        glNormal3f(x,y,z);
}


/* normala definisana sa tackom */
void glutcpp::normal(Tacka t)
{
    glutcpp::normal(t.get_x(),t.get_y(),t.get_z());
}


/* normala definisana sa tackom i homogenom koordinatom */
void glutcpp::normal(Tacka t, float w)
{
    glutcpp::normal(t.get_x(),t.get_y(),t.get_z(),w);
}


/* pravougaonik definisan sa 4 tacke */
void glutcpp::pravougaonik(Tacka a, Tacka b, Tacka c, Tacka d)
{
    glutcpp::begin(GL_QUADS);
        glutcpp::vertex(a);
        glutcpp::vertex(b);
        glutcpp::vertex(c);
        glutcpp::vertex(d);
    glutcpp::end();
}


/* tekst na ekranu sa GLUT_BITMAP_HELVETICA_18 fontom */
void glutcpp::text(float x, float y, std::string s)
{
    glutcpp::text(x,y,s,GLUT_BITMAP_HELVETICA_18);
}


/* tekst na ekranu sa proizvoljnim fontom */
void glutcpp::text(float x, float y, std::string s, void * font)
{
    glRasterPos2f(x,y);
    for(char c : s)
        glutBitmapCharacter(font,c);
}


/* funkcija transformacije za rotaciju koordinatnog sistema za ugao i odredjene koordinate */
void glutcpp::rotate(float ugao, float x, float y, float z)
{
    glRotatef(ugao,x,y,z);
}


/* funkcija transformacije za rotaciju koordinatnog sistema za ugao sa koordinatama tacke */
void glutcpp::rotate(float ugao, Tacka t)
{
    glutcpp::rotate(ugao,t.get_x(),t.get_y(),t.get_z());
}


/* funkcija transformacije za pomeranje koordinatnog sistema pomocu 3 koordinate kao vektor */
void glutcpp::translate(float x, float y, float z)
{
    glTranslatef(x,y,z);
}


/* funkcija transformacije za pomeranje koordinatnog sistema za tacku kao vektor */
void glutcpp::translate(Tacka t)
{
    glutcpp::translate(t.get_x(),t.get_y(),t.get_z());
}


/* stavljanje matrice za transformaciju na stek */
void glutcpp::push()
{
    glPushMatrix();
}


/* skidanje matrice za transformaciju sa steka */
void glutcpp::pop()
{
    glPopMatrix();
}


/* kocka odredjenih dimenzija */
void glutcpp::cube(float size)
{
    glutSolidCube(size);
}


/* ponovo iscrtavanje */
void glutcpp::reDisplay()
{
    glutPostRedisplay();
}


/* brisanje buffera */
void glutcpp::clear(GLenum arg)
{
    glClear(arg);
}


/* zamena buffera */
void glutcpp::swapBuffers()
{
    glutSwapBuffers();
}


/* podesavanja za velicinu prozora */
void glutcpp::reshapeWindow(int width, int height)
{
    glutReshapeWindow(width,height);
}


/* funkcija transformacije za skaliranje pomocu koordinata */
void glutcpp::scale(float x, float y, float z)
{
    glScalef(x,y,z);
}


/* funkcija transformacije za skaliranje pomocu tacke */
void glutcpp::scale(Tacka t)
{
    glScalef(t.get_x(),t.get_y(),t.get_z());
}


/* lopta velicine radius */
void glutcpp::sphere(float radius)
{
    glutSolidSphere(radius,25+radius/5,25+radius/5);
}


/* cilindar sa duzinom (height) i sirinom (radius) */
void glutcpp::cylinder(float radius,float height)
{
    glutSolidCylinder(radius,height,25+radius/5,25+radius/5);
}


/* kupa sa visinom (height) i osnovom (radius) */
void glutcpp::cone(float radius,float height)
{
    glutSolidCone(radius,height,25+radius/5,25+radius/5);
}


/* kvadar sa visinom sirinom i duzinom */
void glutcpp::kvadar(float duzina, float sirina, float visina)
{
    float x=duzina/2;
    float y=visina/2;
    float z=sirina/2;
    glutcpp::normal(0,0,1);
    glutcpp::pravougaonik(Tacka(x,y,z),Tacka(-x,y,z),Tacka(-x,-y,z),Tacka(x,-y,z));
    glutcpp::normal(0,0,-1);
    glutcpp::pravougaonik(Tacka(x,y,-z),Tacka(-x,y,-z),Tacka(-x,-y,-z),Tacka(x,-y,-z));
    glutcpp::normal(0,1,0);
    glutcpp::pravougaonik(Tacka(x,y,z),Tacka(-x,y,z),Tacka(-x,y,-z),Tacka(x,y,-z));
    glutcpp::normal(0,-1,0);
    glutcpp::pravougaonik(Tacka(x,-y,z),Tacka(-x,-y,z),Tacka(-x,-y,-z),Tacka(x,-y,-z));
    glutcpp::normal(1,0,0);
    glutcpp::pravougaonik(Tacka(x,y,z),Tacka(x,-y,z),Tacka(x,-y,-z),Tacka(x,y,-z));
    glutcpp::normal(-1,0,0);
    glutcpp::pravougaonik(Tacka(-x,y,z),Tacka(-x,-y,z),Tacka(-x,-y,-z),Tacka(-x,y,-z));
}


/* pravougaonik koji lezi u z ravni */
void glutcpp::pravougaonik_z(float duzina, float sirina)
{
    float x=duzina/2;
    float y=sirina/2;
    glutcpp::pravougaonik(Tacka(x,y,0),Tacka(x,-y,0),Tacka(-x,-y,0),Tacka(-x,y,0));
}


/* kvadar sa tackama */
void glutcpp::kvadar(Tacka a1,Tacka b1,Tacka c1,Tacka d1,Tacka a2,Tacka b2,Tacka c2,Tacka d2)
{
    glutcpp::normal(0,-1,0);
    glutcpp::pravougaonik(a1,b1,c1,d1);
    glutcpp::normal(0,0,1);
    glutcpp::pravougaonik(a1,b1,b2,a2);
    glutcpp::normal(1,0,0);
    glutcpp::pravougaonik(b1,c1,c2,b2);
    glutcpp::normal(0,0,-1);
    glutcpp::pravougaonik(c1,d1,d2,c2);
    glutcpp::normal(-1,0,0);
    glutcpp::pravougaonik(d1,a1,a2,d2);
    glutcpp::normal(0,1,0);
    glutcpp::pravougaonik(a2,b2,c2,d2);
}


/* grid za podlogu */
void glutcpp::grid(int dimenzija, int korak, float r, float g, float b)
{
    glutcpp::light(GL_OFF);
    glutcpp::color(r, g, b, 1);
    for (int i=-dimenzija; i<=dimenzija; i+=korak)
    {
        glutcpp::begin(GL_LINES);
            {
                    glutcpp::vertex(Tacka(i,0,-dimenzija));
                    glutcpp::vertex(Tacka(i,0,dimenzija));
                    glutcpp::vertex(Tacka(-dimenzija,0,i));
                    glutcpp::vertex(Tacka(dimenzija,0,i));
            }
        glutcpp::end();
    }
    glutcpp::light(GL_ON);
}


/* funkcija za ulazak u FullScreen */
void glutcpp::fullScreen()
{
    glutFullScreen();
}


/* funkcija za ulazak/izlazak u FullScreen */
void glutcpp::fullScreenToggle()
{
    glutFullScreenToggle();
}



/* Funkcija koja menja iz 3D modusa u 2D modus za crtanje na display */
void glutcpp::screenDisplayBegin3D()
{
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


/* Funkcija koja vraca iz 2D u 3D modus radi nastavka rada u 3D posle crtanja na display */
void glutcpp::screenDisplayEnd3D(int ugao,int width,int height,int arg1,int arg2)
{
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(ugao,(float)width/height,arg1,arg2);
}


/* linija sa 2 tacke */
void glutcpp::linija(Tacka a,Tacka b)
{
    glutcpp::begin(GL_LINES);
        glutcpp::vertex(a);
        glutcpp::vertex(b);
    glutcpp::end();
}


/* linija sa koordinatama */
void glutcpp::linija(float x1,float y1,float z1,float x2,float y2,float z2)
{
    glutcpp::linija(Tacka(x1,y1,z1),Tacka(x2,y2,z2));
}
