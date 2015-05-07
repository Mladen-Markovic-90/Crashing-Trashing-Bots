#ifndef GLUT_DISPLAY_H
#define GLUT_DISPLAY_H


#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface za display */
class glutDisplay
{
public:
    /* konstruktor i virtualni destruktor */
    glutDisplay(){}
    virtual ~glutDisplay(){}

    /* prikazuje sadrzaj prozora */
    virtual void show(){}
};


/* klasa za inicijalizaciju display funkcije u glutu */
class glutDisplayInit
{
public:
    /* pokretanje displaya za glut */
    static void run(glutDisplay * d)
    {
        delete display;
        display=d;
        glutDisplayFunc(onDisplay);
    }

    /* ukoliko je potrebno, moze da se uzme pokazivac na Display */
    static glutDisplay * getDisplay()
    {
        return display;
    }

private:
    /* promenljiva koja cuva trenutni display */
    static glutDisplay * display;

    /* konstruktor i destruktor */
    glutDisplayInit(){}
    ~glutDisplayInit(){}

    /* glut input funkcija za crtanje */
    static void onDisplay(void)
    {
        display->show();
    }
};
/* inicijalizacija statickog pokazivaca na null */
glutDisplay * glutDisplayInit::display=nullptr;


#endif // GLUT_DISPLAY_H
