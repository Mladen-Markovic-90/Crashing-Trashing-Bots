#include "global.h"
#include "telo.h"
#include "provera.h"

Telo::Telo(Tacka northWest, Tacka northEast, Tacka southEast, Tacka southWest,
           float radius, Tacka center, float ugao)
    :_northWest(northWest), _northEast(northEast) , _southEast(southEast), _southWest(southWest),
      _radius(radius), _center(center), _ugao(ugao)
{
    _povrsina+=provera::povrsina(northWest,northEast,Tacka(0,0,0));
    _povrsina+=provera::povrsina(northEast,southEast,Tacka(0,0,0));
    _povrsina+=provera::povrsina(southEast,southWest,Tacka(0,0,0));
    _povrsina+=provera::povrsina(southWest,northWest,Tacka(0,0,0));
    //std::cout << "Povrsina je: " << _povrsina << std::endl;
}

Telo::~Telo()
{

}

double Telo::povrsina(const Tacka &NW, const Tacka &NE,
                  const Tacka &SW, const Tacka &SE, const Tacka &spoljna)
{
    double P = 0;
    P += provera::povrsina(NW, SW, spoljna);
    P += provera::povrsina(SW, SE, spoljna);
    P += provera::povrsina(SE, NE, spoljna);
    P += provera::povrsina(NE, NW, spoljna);

    //    std::cout << P << std::endl;
    return P;
}

bool Telo::kolizija(const Telo &t, const Tacka& pomeraj)
{
    double eps = 1;
    if (&t == this)
    return false;

    Tacka prviNW = provera::position(_northWest, _center + pomeraj, _ugao);
    Tacka prviNE = provera::position(_northEast, _center + pomeraj, _ugao);
    Tacka prviSW = provera::position(_southWest, _center + pomeraj, _ugao);
    Tacka prviSE = provera::position(_southEast, _center + pomeraj, _ugao);

    Tacka drugiNW = provera::position(t.getNW(), t.getPos(), t.getUgao());
    Tacka drugiNE = provera::position(t.getNE(), t.getPos(), t.getUgao());
    Tacka drugiSW = provera::position(t.getSW(), t.getPos(), t.getUgao());
    Tacka drugiSE = provera::position(t.getSE(), t.getPos(), t.getUgao());

    if (abs(povrsina(prviNW, prviNE, prviSW, prviSE, drugiNW) - this->getPovrsina()) < eps)
        return true;
    if (abs(povrsina(prviNW, prviNE, prviSW, prviSE, drugiNE) - this->getPovrsina()) < eps)
        return true;
    if (abs(povrsina(prviNW, prviNE, prviSW, prviSE, drugiSW) - this->getPovrsina()) < eps)
        return true;
    if (abs(povrsina(prviNW, prviNE, prviSW, prviSE, drugiSE) - this->getPovrsina()) < eps)
        return true;
    if (abs(povrsina(drugiNW, drugiNE, drugiSW, drugiSE, prviNW) - t.getPovrsina()) < eps)
        return true;
    if (abs(povrsina(drugiNW, drugiNE, drugiSW, drugiSE, prviNE) - t.getPovrsina()) < eps)
        return true;
    if (abs(povrsina(drugiNW, drugiNE, drugiSW, drugiSE, prviSW) - t.getPovrsina()) < eps)
        return true;
    if (abs(povrsina(drugiNW, drugiNE, drugiSW, drugiSE, prviSE) - t.getPovrsina()) < eps)
        return true;

    return false;

}

// binarno pronalazimo dozvoljen koeficijent pomeraja
double Telo::pretraga(const Telo &drugi, const Tacka &pomeraj,
               double min_k, double max_k, int dubina)
{
    if (!kolizija(drugi, pomeraj * max_k))
        return max_k;

    if (dubina > 10)
        return min_k;

    double m = (max_k + min_k) / 2;

    if (kolizija(drugi, pomeraj * m))
        return pretraga(drugi, pomeraj, min_k, m, dubina + 1);
    else
        return pretraga(drugi, pomeraj, m, max_k, dubina + 1);

}
