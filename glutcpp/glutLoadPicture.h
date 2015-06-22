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


#ifndef GLUT_LOAD_PICTURE_H
#define GLUT_LOAD_PICTURE_H


/* ukljucujemo potrebna zaglavlja */
#include <fstream>
#include <cstdlib>
#include "tacka.h"
#include "glutcpp.h"


/* klasa za ucitavanje bitmap slike */
class glutLoadPicture
{
public:
    static void load(std::string path,GLuint ID)
    {
        /* promenljive za podatke bitmap */
        char header[54];
        unsigned int dataPos;
        unsigned int width, height;
        unsigned int imageSize;
        char * data;

        /* otvaramo tok za fajl */
        std::fstream f(path.c_str());

        /* ako je doslo do neke vrste greske, ispisujemo gresku */
        if(!f)
            {
            std::cout << "Image could not be opened" << std::endl;
            return;
            }
        if(!f.read(header,54))
            { /* If not 54 bytes read : problem*/
            std::cout << "Not a correct BMP file" << std::endl;
            return;
            }
        if ( header[0]!='B' || header[1]!='M' )
            {
            std::cout << "Not a correct BMP file" << std::endl;
            return;
            }

        /* izdvajamo podatke iz headera */
        dataPos    = *(int*)&(header[0x0A]);
        imageSize  = *(int*)&(header[0x22]);
        width      = *(int*)&(header[0x12]);
        height     = *(int*)&(header[0x16]);

        /* ukoliko nije inicijalizovan broj u headeru */
        if (imageSize==0)    imageSize=width*height*3;
        if (dataPos==0)      dataPos=54;

        /* rezervisemo prostor za pixele */
        data=(char *)malloc(3*width*height);

        /* pomeramo se na mesto gde su pixeli */
        f.read(data,dataPos-54);

        /* ucitavamo pixele */
        f.read(data,imageSize);

        /* okrecemo pixele da bi bili u RGB, jer su BGR */
        for(unsigned int i=0;i<3*width*height;i=i+3)
            {
            unsigned tmp=data[i];
            data[i]=data[i+2];
            data[i+2]=tmp;
            }

        /* ucitavanje pixela kao texture u glut */
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,ID);
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glDisable(GL_TEXTURE_2D);

        /* oslobadjamo sve sto je visak */
        free(data);
        f.close();

        return;
    }


    /* iscrtavanje odredjene texture */
    static void texture_display(Tacka a,Tacka b,Tacka c,Tacka d,int ID)
    {
        /* ukljucujemo texturu koju cemo iscrtati */
        glBindTexture(GL_TEXTURE_2D,ID);
        glEnable(GL_TEXTURE_2D);
        glutcpp::color(1,1,1,1);

        /* iscrtamo texturu na odredjenom cetvoro-ugaoniku */
        glutcpp::begin(GL_QUADS);
            glTexCoord2f(0,0);
            glutcpp::vertex(a);
            glTexCoord2f(1,0);
            glutcpp::vertex(b);
            glTexCoord2f(1,1);
            glutcpp::vertex(c);
            glTexCoord2f(0,1);
            glutcpp::vertex(d);
        glutcpp::end();

        /* iskljucujemo rad sa teksturama */
        glDisable(GL_TEXTURE_2D);

        return;
    }

private:
    /* konstruktor i destruktor */
    glutLoadPicture(){}
    ~glutLoadPicture(){}
};


#endif // GLUT_LOAD_PICTURE_H
