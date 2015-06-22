/*
    Crashing Trashing Bots is a 3D game in freeglut
    Copyright (C) 2015 Mladen Markovic,Tamara Plazinic,Nikola Banjac

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef GLUTCPP_H
#define GLUTCPP_H


/* ukljucujemo potrebna zaglavlja */
#include <GL/freeglut.h>
#include "tacka.h"
#include <iostream>


/* konstante za ukljuceno/iskljuceno */
#define GL_OFF 0
#define GL_ON 1


/* klasa koja je omotac za freeglut biblioteku */
class glutcpp
{
public:
    /* inicijalizacija freeglut */
    static void init(int argc, char ** argv, int width, int heigth, std::string name);

    /* glMainLoop() -> glut petlja */
    static void start();

    /* glBegin() -> zapocinjemo crtanje */
    static void begin(GLenum);

    /* glEnd() -> zavrsavamo crtanje */
    static void end();

    /* boja nezavisno od svetla */
    static void color(float r,float g,float b,float a);

    /* ukljucivanje ili iskljucivanje svetla sa normalama */
    static void light(int arg);

    /* pozicija svetla */
    static void lightPosition(float x, float y, float z, float w);

    /* sirina linije */
    static void lineWidth(double width);

    /* sluzi za rad u 3D */
    static void projection3D(int width, int height,int ugao,int arg1,int arg2);

    /* sluzi za rad u 2D */
    static void projection2D(int width, int height);

    /* sluzi za prikazivanje u 3D */
    static void modelView3D(float x,float y,float z);

    /* sluzi za prikazivanje u 2D */
    static void modelView2D();

    /* tacka sa 3 koordinate i homogena koordinata */
    static void vertex(float x, float y, float z, float w);

    /* tacka sa 3 koordinate */
    static void vertex(float x, float y, float z);

    /* tacka koja prima tacku */
    static void vertex(Tacka t);

    /* tacka koja prima tacku i homogenu koordinatu */
    static void vertex(Tacka t,float w);

    /* normala definisana sa 3 koordinate i homogena koordinata */
    static void normal(float x, float y, float z, float w);

    /* normala definisana sa 3 koordinate */
    static void normal(float x, float y, float z);

    /* normala definisana sa tackom i homogenom koordinatom */
    static void normal(Tacka t, float w);

    /* normala definisana sa tackom */
    static void normal(Tacka t);

    /* pravougaonik definisan sa 4 tacke */
    static void pravougaonik(Tacka a,Tacka b,Tacka c,Tacka d);

    /* tekst na ekranu sa proizvoljnim fontom */
    static void text(float x,float y,std::string s,void * font);

    /* tekst na ekranu sa GLUT_BITMAP_HELVETICA_18 fontom */
    static void text(float x, float y, std::string s);

    /* funkcija transformacije za rotaciju koordinatnog sistema za ugao i odredjene koordinate */
    static void rotate(float ugao, float x, float y, float z);

    /* funkcija transformacije za rotaciju koordinatnog sistema za ugao sa koordinatama tacke */
    static void rotate(float ugao, Tacka t);

    /* funkcija transformacije za pomeranje koordinatnog sistema pomocu 3 koordinate kao vektor */
    static void translate(float x, float y, float z);

    /* funkcija transformacije za pomeranje koordinatnog sistema za tacku kao vektor */
    static void translate(Tacka t);

    /* stavljanje matrice za transformaciju na steck */
    static void push();

    /* skidanje matrice za transformaciju sa stecka */
    static void pop();

    /* kocka odredjenih dimenzija */
    static void cube(float size);

    /* ponovo iscrtavanje */
    static void reDisplay();

    /* brisanje buffera */
    static void clear(GLenum);

    /* zamena buffera */
    static void swapBuffers();

    /* podesavanja za velicinu prozora */
    static void reshapeWindow(int width,int height);

    /* funkcija transformacije za skaliranje pomocu koordinata */
    static void scale(float x,float y,float z);

    /* funkcija transformacije za skaliranje pomocu tacke */
    static void scale(Tacka t);

    /* lopta velicine radius */
    static void sphere(float radius);

    /* cilindar sa visinom (height) i osnovom (radius) */
    static void cylinder(float radius,float height);

    /* kupa sa visinom (height) i osnovom (radius) */
    static void cone(float radius,float height);

    /* kvadar sa visinom, sirinom i duzinom */
    static void kvadar(float duzina,float sirina,float visina);

    /* pravougaonik koji lezi u z ravni */
    static void pravougaonik_z(float duzina, float sirina);

    /* kvadar sa tackama */
    static void kvadar(Tacka a1,Tacka b1,Tacka c1,Tacka d1,Tacka a2,Tacka b2,Tacka c2,Tacka d2);

    /* grid za podlogu */
    static void grid(int dimenzija, int korak, float r, float g, float b);

    /* funkcija za namestanje kamere */
    static void lookAt(Tacka oko, Tacka fokus);

    /* Funkcija koja menja iz 3D modusa u 2D modus za crtanje na display */
    static void screenDisplayBegin3D();

    /* Funkcija koja vraca iz 2D u 3D modus radi nastavka rada u 3D posle crtanja na display */
    static void screenDisplayEnd3D(int ugao, int width, int height, int arg1, int arg2);

    /* funkcija za ulazak u FullScreen */
    static void fullScreen();

    /* funkcija za ulazak/izlazak u FullScreen */
    static void fullScreenToggle();

    /* linija sa 2 tacke */
    static void linija(Tacka a,Tacka b);

    /* linija sa koordinatama */
    static void linija(float x1,float y1,float z1,float x2,float y2,float z2);
};


#include "glutcpp.cpp"


#endif // GLUTCPP_H
