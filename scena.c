#include <stdlib.h>
#include "funkcije.h"

void scena(){
    
    glPushMatrix();
    
    GLfloat material_ambient[] = { 0.3, 0.1, 0.1, 1 };
    GLfloat material_diffuse[] = { 1, 0.2, 0.2, 1 };
    GLfloat material_specular[] = { 0, 0, 0, 1 };
    GLfloat shininess = 10;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT_AND_BACK,  GL_SHININESS, shininess);
    
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
    
    glPushMatrix();
    
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
        glVertex3f(-50, 0, 100);
        glVertex3f(50, 0, 100);
        glVertex3f(50, 18, 100);
        glVertex3f(-50, 18, 100);
    glEnd();
    glPopMatrix();
    
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
    glPopMatrix();
    
    glPopMatrix();
    
    
}
