#include <stdlib.h>
#include "funkcije.h"

void scena(){
    
    // plafon
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex3f(-50, 18, -50);
        glVertex3f(-50, 18, 100);
        glVertex3f(50, 18, 100);
        glVertex3f(50, 18, -50);
    glEnd();
    
    
    // pod
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex3f(-50, 0, -50);
        glVertex3f(-50, 0, 100);
        glVertex3f(50, 0, 100);
        glVertex3f(50, 0, -50);
    glEnd();
    
    
    // desni zid
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
        glVertex3f(-50, 0, 100);
        glVertex3f(50, 0, 100);
        glVertex3f(50, 18, 100);
        glVertex3f(-50, 18, 100);
    glEnd();
    
    // prednji zid
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex3f(-50, 0, -50);
        glVertex3f(-50, 0, 100);
        glVertex3f(-50, 18, 100);
        glVertex3f(-50, 18, -50);
    glEnd();
    
    // levi zid
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex3f(50, 0, 100);
        glVertex3f(50, 0, -50);
        glVertex3f(50, 18, -50);
        glVertex3f(50, 18, 100);
    glEnd();
    
    
    // zadnji zid
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
        glVertex3f(-50, 0, -50);
        glVertex3f(50, 0, -50);
        glVertex3f(50, 18, -50);
        glVertex3f(-50, 18, -50);
    glEnd();
    
    //ograda
    glPushMatrix();
    
        glTranslatef(0, 0, 15);
        glScalef(25, 1, 1);
        glTranslatef(0, 2, 0);
        glColor3f(0.8,0.8,0.8);
        glutSolidCube(4);
        glColor3f(0,0,0);
        glutWireCube(4);
    glPopMatrix();
    
    
}
