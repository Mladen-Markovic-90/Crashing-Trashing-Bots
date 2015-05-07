#ifndef GLUT_TIMER_LISTENER_H
#define GLUT_TIMER_LISTENER_H


/* klasa koja sluzi kao Interface za animacije */
class glutAnimationTimer
{
public:
    /* konstruktor i virtualni destruktor */
    glutAnimationTimer(){}
    virtual ~glutAnimationTimer(){}

    virtual int getMs() const
    {
        return 0;
    }

    virtual float getTicksPerSecond() const
    {
        return 0;
    }

    /* Funkcija za timer i izracunavanje */
    virtual void timer(int id) const {id=id;}
};

/* klasa za postavljanje timera za animacije */
class glutAnimationTimerInit
{
public:

    static void run(glutAnimationTimer * at)
    {
        delete animationTimer;
        animationTimer=at;
        glutTimerFunc(at->getMs(),onTimer,0);
    }

private:
    /* konstruktor i destruktor */
    glutAnimationTimerInit(){}
    ~glutAnimationTimerInit(){}

    /* glut input funkcija za rad sa vremenom koja prima milisekunde */
    static void onTimer(int id)
    {
        animationTimer->timer(id);
        glutTimerFunc(animationTimer->getMs(),onTimer,0);
    }

    /* promenljiva koja cuva timer za animacije */
    static glutAnimationTimer * animationTimer;
};
/* inicijalizacija statickog pokazivaca na null */
glutAnimationTimer * glutAnimationTimerInit::animationTimer=nullptr;


#endif // GLUT_TIMER_LISTENER_H
