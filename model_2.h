#ifndef MODEL_2
#define MODEL_2


#include "glut.h"

int ugao_tocakk=0;


static void tocakk(float radius,float height)
{
glut::push();
    int ugao=-ugao_tocakk/4;
    glut::rotate(ugao*5,0,0,1);
    ugao_tocakk++;
    glut::color(0.8,0.8,0.8,1);
    glut::cylinder(radius,height);
    glut::translate(0,0,-0.1);
    glut::color(0,0,0,1);
    for(int i=0;i<4;i++)
    {
        glut::push();
            glut::rotate(i*45,0,0,1);
            glut::pravougaonik_z(radius,height/2);
            glut::translate(0,0,height+0.2);
            glut::pravougaonik_z(radius,height/2);
        glut::pop();
    }
glut::pop();
}



static void model_2()
{

    glut::push();
        glut::rotate(180,0,1,0);
        glut::translate(10,5,-10);
        tocakk(5,2);
        glut::translate(-20,0,0);
        tocakk(5,2);
        glut::translate(0,0,18);
        tocakk(5,2);
        glut::translate(20,0,0);
        tocakk(5,2);
    glut::pop();

    glut::push();
        glut::color(0.5,0.5,0.5,1);
        glut::translate(0,6,0);
        glut::kvadar(10,20,8);
    glut::pop();

    glut::push();
        glut::color(0.5,0.5,1,1);
        glut::translate(0,10,0);
        glut::kvadar(Tacka(-15,0,10),Tacka(15,0,10),Tacka(15,0,-10),Tacka(-15,0,-10),
                     Tacka(0,5,5),Tacka(20,5,5),Tacka(20,5,-5),Tacka(0,5,-5));

    glut::pop();

    glut::push();
        glut::color(0.2,0.2,0.2,1);
        glut::translate(17,13,3);
        glut::rotate(90,0,1,0);
        glut::cylinder(1,5);
        glut::rotate(-90,0,1,0);
        glut::translate(0,0,-6);
        glut::rotate(90,0,1,0);
        glut::cylinder(1,5);
    glut::pop();


}


#endif // MODEL_2

