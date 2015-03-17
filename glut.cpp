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


#include <GL/freeglut.h>
#include "glut.h"


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
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
        }
    else
        {
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
