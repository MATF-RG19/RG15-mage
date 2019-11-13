#include <stdlib.h>
#include "funkcije.h"

void modelLika(){
    
    //desna ruka
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(-1, 2.5, 0);
    glScalef(1, 3, 1);
    glTranslatef(-0.5, 0.5, 0.5);
    glutSolidCube(1);
    
    glColor3f(0, 0, 0);
    glutWireCube(1);
    glPopMatrix();
    
    //leva ruka
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(1, 2.5, 0);
    glScalef(1, 3, 1);
    glTranslatef(0.5, 0.5, 0.5);
    glutSolidCube(1);
    
    glColor3f(0, 0, 0);
    glutWireCube(1);
    glPopMatrix();
    
    //glava
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(0, 6, 0.5);
    glutSolidCube(1);
    
    glColor3f(0, 0, 0);
    glutWireCube(1);
    glPopMatrix();
    
        
    //torzo
    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef(0, 3, 0);
    glScalef(2, 2.5, 1);
    glTranslatef(0, 0.5, 0.5);
    glutSolidCube(1);
    
    glColor3f(0, 0, 0);
    glutWireCube(1);
    glPopMatrix();
    
    
    //desna noga
    glPushMatrix();
    glColor3f(0, 0, 1);
    glScalef(1, 3, 1);
    glTranslatef(-0.5, 0.5, 0.5);
    glutSolidCube(1);
    
    glColor3f(0, 0, 0);
    glutWireCube(1);
    glPopMatrix();
    
    
    //leva noga
    glPushMatrix();
    glColor3f(0, 0, 1);
    glScalef(1, 3, 1);
    glTranslatef(0.5, 0.5, 0.5);
    glutSolidCube(1);
    
    glColor3f(0, 0, 0);
    glutWireCube(1);
    glPopMatrix();
}
