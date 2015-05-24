#ifndef PROVERA_H
#define PROVERA_H


#include "glutcpp/tacka.h"
#include "vektor3d.h"

class provera
{
public:
    static double povrsina(Tacka a,Tacka b,Tacka c)
    {
        Tacka vec1=Vektor3D::vektor(a,b);
        Tacka vec2=Vektor3D::vektor(b,c);
        return Vektor3D::duzina(Vektor3D::vektorskiProizvod(vec1,vec2));
    }

    // Racuna koordinate u svetskom koordinatnom sistemu
    static Tacka position(Tacka t,Tacka center,float ugao)
    {
        Tacka tmp=Tacka(0,0,0);
        double pi=(M_PI*1.0);
        tmp.set_x(t.get_x()*std::cos((-ugao/180.0)*pi)+t.get_z()*std::sin((-ugao/180.0)*pi));
        tmp.set_z(t.get_x()*std::sin((ugao/180.0)*pi)+t.get_z()*std::cos((-ugao/180.0)*pi));
        tmp.add(center);
        return tmp;
    }


private:
    provera();
    ~provera();

};

#endif // PROVERA_H

