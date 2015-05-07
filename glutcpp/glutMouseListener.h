#ifndef GLUT_MOUSE_LISTENER_H
#define GLUT_MOUSE_LISTENER_H


#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface osluskivac za dugmad misa */
class glutMouseListener
{
public:
    /* konstruktor i virtualni destruktor */
    glutMouseListener(){}
    virtual ~glutMouseListener(){}

    /* Desavanje na osnovu klika misa */
    void mouse(int button,int state,int x,int y) const
    {button=button;state=state;x=x;y=y;}
};


/* klasa za postavljanje osluskivaca za dugmad misa u glutu */
class glutMouseListenerInit
{
public:
    /* pokretanje glut osluskivac za poziciju misa */
    static void run(glutMouseListener * ml)
    {
        delete mouseListener;
        mouseListener=ml;
        glutMouseFunc(onMouse);
    }

    /* ukoliko je potrebno, moze da se uzme pokazivac na mouseListener */
    static glutMouseListener * getMouseListener()
    {
        return mouseListener;
    }

private:
    /* promenljiva koja cuva osluskivac za dugmad misa */
    static glutMouseListener * mouseListener;

    /* konstruktor i destruktor */
    glutMouseListenerInit(){}
    ~glutMouseListenerInit(){}

    /* glut input funkcija za citanje stanje dugmad misa */
    static void onMouse(int button,int state,int x,int y)
    {
        mouseListener->mouse(button,state,x,y);
    }
};
/* inicijalizacija statickog pokazivaca na null */
glutMouseListener * glutMouseListenerInit::mouseListener=nullptr;


#endif // GLUT_MOUSE_LISTENER_H
