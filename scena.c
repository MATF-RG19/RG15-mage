#include <stdlib.h>
#include "header.h"
#include "image.h"

void scena(){
    
    glPushMatrix();
    
    
    
    /*GLfloat material_ambient[] = { 0.3, 0.1, 0.1, 1 };
    GLfloat material_diffuse[] = { 1, 0.2, 0.2, 1 };
    GLfloat material_specular[] = { 0, 0, 0, 1 };
    GLfloat shininess = 10;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT_AND_BACK,  GL_SHININESS, shininess);*/
    
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
    
    
    
    /*
    
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
        glVertex3f(-50, 0, 100);
        glVertex3f(50, 0, 100);
        glVertex3f(50, 18, 100);
        glVertex3f(-50, 18, 100);
    glEnd();
    */
    
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
    
    
        /*glVertex3f(-50, 0, -50);
        glVertex3f(-50, 0, 100);
        glVertex3f(-50, 18, 100);
        glVertex3f(-50, 18, -50);*/
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
    
        /*glVertex3f(50, 0, 100);
        glVertex3f(50, 0, -50);
        glVertex3f(50, 18, -50);
        glVertex3f(50, 18, 100);*/
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
    
    //ograda
    /*glPushMatrix();
    
        glTranslatef(0, 0, 15);
        glScalef(25, 1, 1);
        glTranslatef(0, 2, 0);
        glColor3f(0.8,0.8,0.8);
        glutSolidCube(4);
    glPopMatrix();*/
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glPopMatrix();
}


















