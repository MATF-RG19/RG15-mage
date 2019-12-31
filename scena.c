#include <stdlib.h>
#include "header.h"
#include "image.h"

void scena(){
    
    glPushMatrix();
    

    // plafon
    
    glBindTexture(GL_TEXTURE_2D, names[2]);
    
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex3f(-50, 18, -50);
        
        glTexCoord2f(15, 0);
        glVertex3f(-50, 18, 100);
        
        glTexCoord2f(15, 8);
        glVertex3f(50, 18, 100);
        
        glTexCoord2f(0, 8);
        glVertex3f(50, 18, -50);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, names[1]);
    
    
    // pod
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex3f(-50, 0, -50);
        
        glTexCoord2f(15, 0);
        glVertex3f(-50, 0, 100);
        
        glTexCoord2f(15, 8);
        glVertex3f(50, 0, 100);
        
        glTexCoord2f(0, 8);
        glVertex3f(50, 0, -50);
    glEnd();

    
    glBindTexture(GL_TEXTURE_2D, names[0]);
    
    // prednji zid
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-50, 0, 100);

        glTexCoord2f(20, 0);
        glVertex3f(50, 0, 100);

        glTexCoord2f(20, 4);
        glVertex3f(50, 18, 100);

        glTexCoord2f(0, 4);
        glVertex3f(-50, 18, 100);
        
    glEnd();
    
   
    // desni zid
    
    glBegin(GL_QUADS);
    
        glNormal3f(-1, 0, 0);
        
        glTexCoord2f(0, 0);
        glVertex3f(-50, 0, -50);
        
        glTexCoord2f(25, 0);
        glVertex3f(-50, 0, 100);
        
        glTexCoord2f(25, 4);
        glVertex3f(-50, 18, 100);
        
        glTexCoord2f(0, 4);
        glVertex3f(-50, 18, -50);
    
    glEnd();
    
    // levi zid
    
    glBegin(GL_QUADS);
    
        glNormal3f(-1, 0, 0);
        
        glTexCoord2f(0, 0);
        glVertex3f(50, 0, -50);
        
        glTexCoord2f(25, 0);
        glVertex3f(50, 0, 100);
        
        glTexCoord2f(25, 4);
        glVertex3f(50, 18, 100);
        
        glTexCoord2f(0, 4);
        glVertex3f(50, 18, -50);
        
    glEnd();
    
    
    // zadnji zid
    
    glBegin(GL_QUADS);
    
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-50, 0, -50);

        glTexCoord2f(20, 0);
        glVertex3f(50, 0, -50);

        glTexCoord2f(20, 4);
        glVertex3f(50, 18, -50);

        glTexCoord2f(0, 4);
        glVertex3f(-50, 18, -50);
    
        
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glPopMatrix();
}


















