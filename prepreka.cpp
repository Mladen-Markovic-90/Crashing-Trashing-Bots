#include "prepreka.h"
#include "glutcpp/glutcpp.h"

Prepreka::Prepreka(int stranica, Tacka centar, float r, float g, float b)
    : Telo(centar + Tacka(stranica/2, 0, stranica/2),
           centar + Tacka(stranica/2, 0, -stranica/2),
           centar + Tacka(-stranica/2, 0, -stranica/2),
           centar + Tacka(-stranica/2, 0, stranica/2),
           0, //TODO: popravi ako bude potrebe
           centar,
           0),
      _duzina(stranica),
      _sirina(stranica),
      _visina(stranica),
      _r(r), _g(g), _b(b)
{
}

Prepreka::Prepreka(int duzina, int visina, int sirina, Tacka centar, float r, float g, float b)
    : Telo(centar + Tacka(sirina/2, 0, duzina/2),
           centar + Tacka(sirina/2, 0, -duzina/2),
           centar + Tacka(-sirina/2, 0, -duzina/2),
           centar + Tacka(-sirina/2, 0, duzina/2),
           0, //TODO: popravi ako bude potrebe
           centar,
           0),
      _duzina(duzina),
      _sirina(sirina),
      _visina(visina),
      _r(r), _g(g), _b(b)
{
}

Prepreka::~Prepreka()
{
}

void Prepreka::draw()
{
    glutcpp::color(_r, _g, _b, 1.0);

    glutcpp::push();
    glutcpp::translate(_center);
    glutcpp::kvadar(_duzina, _sirina, _visina);
    glutcpp::pop();
}
