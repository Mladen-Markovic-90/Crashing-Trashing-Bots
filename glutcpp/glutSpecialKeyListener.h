#ifndef GLUT_SPECIAL_KEY_LISTENER_H
#define GLUT_SPECIAL_KEY_LISTENER_H


#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface za osluskivac specijalnih karaktera */
class glutSpecialKeyListener
{
public:
    /* konstruktor i virtualni destruktor */
    glutSpecialKeyListener(){}
    virtual ~glutSpecialKeyListener(){}

    /* radnja za stisnute specijalne karatere */
    virtual void keyDown(int key,int x,int y) const
    {key=key;x=x;y=y;}

    /* radnja za otpustene specijalne karaktere */
    virtual void keyUp(int key,int x,int y) const
    {key=key;x=x;y=y;}
};


/* klasa za postavljanje osluskivaca za specijalne karaktere u glutu */
class glutSpecialKeyListenerInit
{
public:
    /* pokretanje glut osluskivac za specijalne karaktere */
    static void run(glutSpecialKeyListener * skl)
    {
        delete specialKeyListener;
        specialKeyListener=skl;
        glutSpecialFunc(keyDown);
        glutSpecialUpFunc(keyUp);
    }

private:
    /* konstruktor i destruktor */
    glutSpecialKeyListenerInit(){}
    ~glutSpecialKeyListenerInit(){}

    /* glut input funkcija za citanje specijalnih stisnutih karaktera sa tastature */
    static void keyDown(int key, int x, int y)
    {
        specialKeyListener->keyDown(key,x,y);
    }

    /* glut input funkcija za citanje specijalnih otpustenih karaktera sa tastature */
    static void keyUp(int key, int x, int y)
    {
        specialKeyListener->keyUp(key,x,y);
    }

    /* promenljiva koja cuva osluskivac za specijalne karakter */
    static glutSpecialKeyListener * specialKeyListener;
};
/* inicijalizacija statickog pokazivaca na null */
glutSpecialKeyListener * glutSpecialKeyListenerInit::specialKeyListener=nullptr;


#endif // GLUT_SPECIAL_KEY_LISTENER_H
