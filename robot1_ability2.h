#ifndef ROBOT1_ABILITY2_H
#define ROBOT1_ABILITY2_H


class Robot1_ability2
{
public:
    Robot1_ability2();
    ~Robot1_ability2();
private:
    /* sluzi za poziciju i rotaciju rakete */
    Tacka tacka_raketa=Tacka(0,0,0);
    Tacka tacka_raketa_help=_center;
    int ugao_raketa=0;
};

#endif // ROBOT1_ABILITY2_H
