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


#include "glut.h"
#include "tacka.h"


void glut::init(int argc,char ** argv,int width,int heigth,char * name)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB |  GLUT_DEPTH |  GLUT_DOUBLE);

    /*glutInitWindowSize(2*(X_2D+margineX),2*(Y_2D+margineY));*/
    glutInitWindowSize(width,heigth);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(name);

    const GLfloat lightambient[4]={0.5f,0.5f,0.5f,1.0f};
    const GLfloat lightdiffuse[4]={0.7f,0.7f,0.7f,1.0f};
    const GLfloat lightspecular[4]={0.9f,0.9f,0.9f,1.0f};
    glLightfv(GL_LIGHT0,GL_AMBIENT,lightambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightdiffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,lightspecular);



    glClearColor(1,1,1,1);
}


void glut::start()
{
    glutMainLoop();
}


void glut::begin(GLenum arg)
{
    glBegin(arg);
}


void glut::end()
{
    glEnd();
}

/*
void glut::display(void (*func)(void))
{
    glutDisplayFunc(*func);
}*/


void glut::light(int arg)
{
    if(arg==GL_ON)
        {
        glEnable(GL_NORMALIZE);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
        }
    else
        {
        glDisable(GL_NORMALIZE);
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
        }
}


void glut::color(float r, float g, float b, float a)
{
    glColor4f(r,g,b,a);
    const GLfloat colorambient[4]={r*0.5f,g*0.5f,b*0.5f,a};
    const GLfloat colordiffuse[4]={r*0.7f,g*0.7f,b*0.7f,a};
    const GLfloat colorspecular[4]={r*0.9f,g*0.9f,b*0.9f,a};
    glMaterialfv(GL_DIFFUSE,GL_FRONT_AND_BACK,colordiffuse);
    glMaterialfv(GL_AMBIENT,GL_FRONT_AND_BACK,colorambient);
    glMaterialfv(GL_SPECULAR,GL_FRONT_AND_BACK,colorspecular);
}


void glut::projection3D(int width, int height, int ugao, int arg1,int arg2)
{
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(ugao, (float) width / height, arg1, arg2);
}


void glut::projection2D(int width,int height)
{
    glDisable(GL_DEPTH_TEST);
    glViewport(0, 0, width, height);

    /* Brisemo podesavanje matrice da bi bili u 2D */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}


void glut::modelview2D()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void glut::modelview3D(float x,float y,float z)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x,y,z,0, 0, 0, 0, 1, 0);
}


void glut::lightposition(float x, float y, float z,float w)
{
    float array[4]={x,y,z,w};
    glLightfv(GL_LIGHT0,GL_POSITION,array);
}


void glut::vertex(float x, float y, float z,float w)
{
    glVertex4f(x,y,z,w);
}


void glut::vertex(float x, float y, float z)
{
    glVertex3f(x,y,z);
}



void glut::vertex(Tacka t)
{
    glVertex3f(t.get_x(),t.get_y(),t.get_z());
}


void glut::vertex(Tacka t, float w)
{
    glVertex4f(t.get_x(),t.get_y(),t.get_z(),w);
}


void glut::normal(float x, float y, float z)
{
    glNormal3f(x,y,z);
}


void glut::normal(float x, float y, float z, float w)
{
    if(w>0.001 && w<-0.001)
        glNormal3f(x/w,y/w,z/w);
    else
        glNormal3f(x/w,y/w,z/w);
}


void glut::normal(Tacka t)
{
    glut::normal(t.get_x(),t.get_y(),t.get_z());
}


void glut::normal(Tacka t, float w)
{
    glut::normal(t.get_x(),t.get_y(),t.get_z(),w);
}


void glut::pravougaonik(Tacka a, Tacka b, Tacka c, Tacka d)
{
    glut::begin(GL_QUADS);
        glut::vertex(a);
        glut::vertex(b);
        glut::vertex(c);
        glut::vertex(d);
    glut::end();
}
