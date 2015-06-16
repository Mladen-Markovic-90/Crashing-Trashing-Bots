#ifndef PREPREKA_H
#define PREPREKA_H

#include "telo.h"

class Prepreka : public Telo
{
public:
    Prepreka(int stranica, Tacka centar, float r, float g, float b);

    Prepreka(int duzina, int visina, int sirina, Tacka centar, float r, float g, float b);

    ~Prepreka();

    void draw();

private:
    int _duzina;
    int _sirina;
    int _visina;

    int _r, _g, _b;
};

#include "prepreka.cpp"

#endif // PREPREKA_H
