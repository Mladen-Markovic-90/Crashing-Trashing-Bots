#ifndef GLUT_NORMAL_KEY_LISTENER_H
#define GLUT_NORMAL_KEY_LISTENER_H


#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface za osluskivac obicnih karaktera */
class glutNormalKeyListener
{
public:
    /* konstruktor i virtualni destruktor */
    glutNormalKeyListener(){}
    virtual ~glutNormalKeyListener(){}

    /* radnja za stisnute obicne karatere */
    virtual void keyDown(unsigned char normalKey,int x,int y) const
    {normalKey=normalKey;x=x;y=y;}

    /* radnja za otpustene obicne karaktere */
    virtual void keyUp(unsigned char normalKey,int x,int y) const
    {normalKey=normalKey;x=x;y=y;}
};


/* klasa za postavljanje osluskivaca za obicne karaktere u glutu */
class glutNormalKeyListenerInit
{
public:
    /* pokretanje glut osluskivac za obicne karaktere */
    static void run(glutNormalKeyListener * nkl)
    {
        delete normalKeyListener;
        normalKeyListener=nkl;
        glutKeyboardFunc(keyDown);
        glutKeyboardUpFunc(keyUp);
    }

    /* ukoliko je potrebno, moze da se uzme pokazivac na normalKeyListener */
    static glutNormalKeyListener * getNormalKeyListener()
    {
        return normalKeyListener;
    }

private:
    /* promenljiva koja cuva osluskivac za obicnih karakter */
    static glutNormalKeyListener * normalKeyListener;

    /* konstruktor i destruktor */
    glutNormalKeyListenerInit(){}
    ~glutNormalKeyListenerInit(){}

    /* glut input funkcija za citanje stisnutih obicnih karaktera sa tastature */
    static void keyDown(unsigned char normalKey, int x, int y)
    {
        normalKeyListener->keyDown(normalKey,x,y);
    }

    /* glut input funkcija za citanje otpustenih karaktera sa tastature */
    static void keyUp(unsigned char normalKey, int x, int y)
    {
        normalKeyListener->keyUp(normalKey,x,y);
    }
};
/* inicijalizacija statickog pokazivaca na null */
glutNormalKeyListener * glutNormalKeyListenerInit::normalKeyListener=nullptr;


#endif // GLUT_NORMAL_KEY_LISTENER_H
