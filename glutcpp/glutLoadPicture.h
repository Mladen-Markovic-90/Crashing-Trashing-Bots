#ifndef GLUT_LOAD_PICTURE_H
#define GLUT_LOAD_PICTURE_H


#include <iostream>
#include <fstream>
#include <cstdlib>
#include "tacka.h"
#include "glutcpp.h"


class glutLoadPicture
{
public:
    static void load(std::string path,GLuint ID)
    {
        char header[54];
        unsigned int dataPos;
        unsigned int width, height;
        unsigned int imageSize;
        char * data;

        std::fstream f(path.c_str());

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

        dataPos    = *(int*)&(header[0x0A]);
        imageSize  = *(int*)&(header[0x22]);
        width      = *(int*)&(header[0x12]);
        height     = *(int*)&(header[0x16]);
        if (imageSize==0)    imageSize=width*height*3;
        if (dataPos==0)      dataPos=54;
        data=(char *)malloc(3*width*height);
        f.read(data,dataPos-54);
        f.read(data,imageSize);
        for(unsigned int i=0;i<3*width*height;i=i+3)
            {
            unsigned tmp=data[i];
            data[i]=data[i+2];
            data[i+2]=tmp;
            }
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,ID);
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glDisable(GL_TEXTURE_2D);
        free(data);
        f.close();
        return;
    }


    /* iscrtavanje odredjene texture */
    static void texture_display(Tacka a,Tacka b,Tacka c,Tacka d,int ID)
    {
    glBindTexture(GL_TEXTURE_2D,ID);
    glEnable(GL_TEXTURE_2D);
    glutcpp::color(1,1,1,1);
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
    glDisable(GL_TEXTURE_2D);
    return;
    }

private:
    glutLoadPicture(){}
    ~glutLoadPicture(){}
};


#endif // GLUT_LOAD_PICTURE_H
