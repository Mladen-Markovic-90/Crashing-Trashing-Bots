#include "prepreka.h"
#include "glutcpp/glutcpp.h"


Prepreka::Prepreka(int stranica, Tacka centar, float r, float g, float b)
    : Telo(Tacka(stranica/2, 0, stranica/2),
           Tacka(stranica/2, 0, -stranica/2),
           Tacka(-stranica/2, 0, -stranica/2),
           Tacka(-stranica/2, 0, stranica/2),
           0, //TODO: popravi ako bude potrebno
           centar,
           90),
      _duzina(stranica),
      _sirina(stranica),
      _visina(stranica),
      _r(r), _g(g), _b(b)
{}


Prepreka::Prepreka(int duzina, int visina, int sirina, Tacka centar, float r, float g, float b)
    : Telo(Tacka(-sirina/2, 0, duzina/2),
           Tacka(sirina/2, 0, duzina/2),
           Tacka(sirina/2, 0, -duzina/2),
           Tacka(-sirina/2, 0, -duzina/2),
           0, //TODO: popravi ako bude potrebno
           centar,
           90),
      _duzina(duzina),
      _sirina(sirina),
      _visina(visina),
      _r(r), _g(g), _b(b)
{}


void Prepreka::draw()
{
    glutcpp::push();
        glutcpp::color(_r, _g, _b, 1.0);
        glutcpp::translate(0, _visina/2, 0);
        glutcpp::translate(_center);
        glutcpp::kvadar(_duzina, _sirina, _visina);
    glutcpp::pop();
}
