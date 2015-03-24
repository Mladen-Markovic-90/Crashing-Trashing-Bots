#ifndef MODEL_3
#define MODEL_3


#include "glut.h"

int ugao_tocak3=0;




static void model_3()
{
    glut::rotate(21*ugao_tocak3,0,-1,0);
    ugao_tocak3++;
    glut::push();
        glut::color(0.5,0.5,0.5,1);
        glut::translate(0,10,0);
        glut::rotate(90,1,0,0);
        glut::cone(15,15);
    glut::pop();

    glut::push();
        glut::kvadar(Tacka(5,0,5),Tacka(-5,0,5),Tacka(-5,0,-5),Tacka(5,0,-5),
                     Tacka(5,1,5),Tacka(-5,1,5),Tacka(-5,1,-5),Tacka(5,1,-5));
        glut::rotate(45,0,1,0);
        glut::kvadar(Tacka(5,0,5),Tacka(-5,0,5),Tacka(-5,0,-5),Tacka(5,0,-5),
                     Tacka(5,1,5),Tacka(-5,1,5),Tacka(-5,1,-5),Tacka(5,1,-5));
    glut::pop();


    glut::push();
        glut::color(0.1,0.1,0.1,1);
        glut::translate(0,12,0);
        glut::rotate(90,1,0,0);
        glut::cylinder(15,2);
    glut::pop();


    glut::push();
        glut::translate(0,11,0);
        glut::color(0.5,0.5,0.5,1);
        for(int i=0;i<8;i++)
        {
            glut::push();
            glut::rotate(i*45,0,1,0);
            glut::translate(0,0,15);
            glut::kvadar(Tacka(0,1,0),Tacka(0,1,0),Tacka(0,0,10),Tacka(5,1,0),
                         Tacka(0,-1,0),Tacka(0,-1,0),Tacka(0,0,10),Tacka(5,-1,0));
            glut::pop();
        }

    glut::pop();


}





#endif // MODEL_3

