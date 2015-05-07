#ifndef GLUT_RESHAPE_LISTENER_H
#define GLUT_RESHAPE_LISTENER_H


#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface za display */
class glutReshapeListener
{
public:
    /* konstruktor i virtualni destruktor */
    glutReshapeListener(){}
    virtual ~glutReshapeListener(){}

    /* Obrada prikaza za prozor u zavisnosti od modusa */
    virtual void reshape(int width,int height)
    {width=width;height=height;}

    virtual int getWindowWidth() const {return 0;}

    virtual int getWindowHeight() const {return 0;}
};


/* klasa za postavljanje osluskivaca za promenu velicine prozora u glutu */
class glutReshapeListenerInit
{
public:
    /* pokretanje glut osluskivac za  promenu velicine prozora */
    static void run(glutReshapeListener * rl)
    {
        delete reshapeListener;
        reshapeListener=rl;
        glutReshapeFunc(onReshape);
    }

    /* ukoliko je potrebno, moze da se uzme pokazivac na motionListener */
    static glutReshapeListener * getReshapeListener()
    {
        return reshapeListener;
    }

private:
    /* konstruktor i destruktor */
    glutReshapeListenerInit(){}
    ~glutReshapeListenerInit(){}

    /* glut input funkcija za podesavanje prozora */
    static void onReshape(int width,int height)
    {
        reshapeListener->reshape(width,height);
    }

    /* promenljiva koja cuva osluskivac za promenu velicine prozora */
    static glutReshapeListener * reshapeListener;
};
/* inicijalizacija statickog pokazivaca na null */
glutReshapeListener * glutReshapeListenerInit::reshapeListener=nullptr;


#endif // GLUT_RESHAPE_LISTENER_H
