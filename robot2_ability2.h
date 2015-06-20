#ifndef ROBOT2_ABILITY2_H
#define ROBOT2_ABILITY2_H


class Robot2_ability2
{
public:
    Robot2_ability2();
    ~Robot2_ability2();
private:
    /* sluzi za poziciju i rotaciju lasera */
    Tacka tacka_laser=Tacka(0,0,0);
    Tacka tacka_laser_help=_center;
    int ugao_laser=0;
};

#endif // ROBOT2_ABILITY2_H
