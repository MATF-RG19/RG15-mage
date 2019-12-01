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

void altar(float x, float y){
    
    glPushMatrix();
    
    glTranslatef(x, 0, y);
    glTranslatef(2, 0, 2);
    
    //postolje
    glPushMatrix();
        glScalef(1, 0.25, 1);
        glTranslatef(0, 2, 0);
        glColor3f(0.8,0.8,0.8);
        glutSolidCube(4);
        glColor3f(0,0,0);
        glutWireCube(4);
    glPopMatrix();
    
    
    //stub
    glPushMatrix();
    
        glTranslatef(0, 1, 0);
        glScalef(3, 3, 3);        
        glTranslatef(0, 0.5, 0);
        
        glColor3f(0.8,0.8,0.8);
        glutSolidCube(1);
        
        glColor3f(0,0,0);
        glutWireCube(1);
    
    glPopMatrix();
    
    
    //vrh
    glPushMatrix();
    
        glTranslatef(0, 4, 0);
        glScalef(1, 0.25, 1);
        glTranslatef(0, 2, 0);
        glColor3f(0.8,0.8,0.8);
        glutSolidCube(4);
        glColor3f(0,0,0);
        glutWireCube(4);
    glPopMatrix();
    
    
    glPopMatrix();
    
}

void munja(){
    
    
    glPushMatrix();
    glScalef(0.5,0.5,1);
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(0,3,0);
        glVertex3f(-1,3,0);
        glVertex3f(-1,3,0.5);
        glVertex3f(0,3,0.5);
    glEnd();
    
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0,3,0);
        glVertex3f(-1,3,0);
        glVertex3f(-1,3,0.5);
        glVertex3f(0,3,0.5);
    glEnd();
    
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(-1,3,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0,0.5);
        glVertex3f(-1,3,0.5);
    glEnd();
    
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(-1,3,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0,0.5);
        glVertex3f(-1,3,0.5);
    glEnd();
    
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(0,2,0);
        glVertex3f(0,2,0.5);
        glVertex3f(0,0,0.5);
    glEnd();
    
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0,0,0);
        glVertex3f(0,2,0);
        glVertex3f(0,2,0.5);
        glVertex3f(0,0,0.5);
    glEnd();
    
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(1,2,0);
        glVertex3f(0,2,0);
        glVertex3f(0,2,0.5);
        glVertex3f(1,2,0.5);
    glEnd();
    
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0,0,0);
        glVertex3f(0,2,0);
        glVertex3f(0,2,0.5);
        glVertex3f(0,0,0.5);
    glEnd();
    
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(0,5,0);
        glVertex3f(0,2,0);
        glVertex3f(1,2,0.5);
        glVertex3f(0,5,0.5);
    glEnd();
    
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0,5,0);
        glVertex3f(1,2,0);
        glVertex3f(1,2,0.5);
        glVertex3f(0,5,0.5);
    glEnd();
    
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(0,5,0);
        glVertex3f(0,3,0);
        glVertex3f(0,3,0.5);
        glVertex3f(0,5,0.5);
    glEnd();
    
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0,5,0);
        glVertex3f(0,3,0);
        glVertex3f(0,3,0.5);
        glVertex3f(0,5,0.5);
    glEnd();
    
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(0,3,0);
        glVertex3f(-1,3,0);
        glVertex3f(0,0,0);
        glVertex3f(0,2,0);
        glVertex3f(1,2,0);
        glVertex3f(0,5,0);
    glEnd();
    
    
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0,3,0);
        glVertex3f(-1,3,0);
        glVertex3f(0,0,0);
        glVertex3f(0,2,0);
        glVertex3f(1,2,0);
        glVertex3f(0,5,0);
    glEnd();
    
    
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(0,3,0);
        glVertex3f(-1,3,0);
        glVertex3f(0,0,0);
        glVertex3f(0,2,0);
        glVertex3f(1,2,0);
        glVertex3f(0,5,0);
    glEnd();
    
    
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0,3,0);
        glVertex3f(-1,3,0);
        glVertex3f(0,0,0);
        glVertex3f(0,2,0);
        glVertex3f(1,2,0);
        glVertex3f(0,5,0);
    glEnd();
    glPopMatrix();
    
    glPopMatrix();
}

void vatraDeo(float x){
    int i;
    for(i=0; i < NUMBER_OF_DOTS; i++){
        /*glColor3f(x,x,0);
        glBegin(GL_POINTS);
        glVertex3f(cos(PI + i*PI/NUMBER_OF_DOTS),
                   sin(PI + i*PI/NUMBER_OF_DOTS),
                   0);
        glVertex3f(-1.5 + 2.5*cos(i*PI/3.4/NUMBER_OF_DOTS),
                   2.5*sin(i*PI/NUMBER_OF_DOTS/3.4),
                   0);
        glVertex3f(1.5 + 2.5*cos(i*PI/3.4/NUMBER_OF_DOTS+PI-PI/3.4),
                   2.5*sin(i*PI/NUMBER_OF_DOTS/3.4+PI-PI/3.4),
                   0);
        glEnd();*/
        
        glColor3f(1,x,0);
        glBegin(GL_POLYGON);
        glVertex3f(cos(PI + i*PI/NUMBER_OF_DOTS),
                   sin(PI + i*PI/NUMBER_OF_DOTS),
                   0);
        glVertex3f(-1.5 + 2.5*cos(i*PI/3.4/NUMBER_OF_DOTS),
                   2.5*sin(i*PI/NUMBER_OF_DOTS/3.4),
                   0);
        glVertex3f(1.5 + 2.5*cos(i*PI/3.4/NUMBER_OF_DOTS+PI-PI/3.4),
                   2.5*sin(i*PI/NUMBER_OF_DOTS/3.4+PI-PI/3.4),
                   0);
        glEnd();
    }
}

void vatra(){
    
    
    glPushMatrix();
    
    glTranslatef(0,0.5,0);
    
    int i;
    float j;
    for(j=0; j<0.5 ;j+=0.01){ //popunjava prostor izmedju
        glPushMatrix();
        glTranslatef(0,0,j);
        
        for(i=0; i<NUMBER_OF_DOTS; i++){
            glColor3f(1,0,0);
            glBegin(GL_POINTS);
            
            glVertex3f(cos(PI + i*PI/NUMBER_OF_DOTS),
                   sin(PI + i*PI/NUMBER_OF_DOTS),
                   0);
            glVertex3f(-1.5 + 2.5*cos(i*PI/3.4/NUMBER_OF_DOTS),
                   2.5*sin(i*PI/NUMBER_OF_DOTS/3.4),
                   0);
            glVertex3f(1.5 + 2.5*cos(i*PI/3.4/NUMBER_OF_DOTS+PI-PI/3.4),
                   2.5*sin(i*PI/NUMBER_OF_DOTS/3.4+PI-PI/3.4),
                   0);
            
            glEnd(); 
        }
        glPopMatrix();
    } 
    
    vatraDeo(0);
    
    glPushMatrix();
    glTranslatef(0,0,-0.01);
    glScalef(0.5, 0.5, 1);
    vatraDeo(1);
    glPopMatrix();
    
    glPushMatrix();
    
    glTranslatef(0,0, 0.5);
    glRotatef(180, 0, 1, 0);
    
    vatraDeo(0);
    
    glPushMatrix();
    glTranslatef(0,0,-0.01);
    glScalef(0.5, 0.5, 1);
    vatraDeo(1);
    glPopMatrix();
    
    glPopMatrix();
    
    glPopMatrix();
}

void pahuljaDeo(){
    
    
    
    glColor3f(0,0,0.8);
    glBegin(GL_POLYGON);
    
        glVertex3f(-0.2,0,0);
        glVertex3f(0.2,0,0);
        glVertex3f(0.2,2,0);
        glVertex3f(-0.2,2,0);
    
    glEnd();
    
    
    glPushMatrix();
    
    glTranslatef(0,1,0);
    glRotatef(50, 0, 0, 1);
    
    glBegin(GL_POLYGON);
    
        glVertex3f(-0.15,0,0);
        glVertex3f(0.15,0,0);
        glVertex3f(0.15,1,0);
        glVertex3f(-0.15,1,0);
    
    glEnd();
    
    glPopMatrix();
    
    glPushMatrix();
    
    glTranslatef(0,1,0);
    glRotatef(-50, 0, 0, 1);
    
    glBegin(GL_POLYGON);
    
        glVertex3f(-0.15,0,0);
        glVertex3f(0.15,0,0);
        glVertex3f(0.15,1,0);
        glVertex3f(-0.15,1,0);
    
    glEnd();
    
    glPopMatrix();
    
    
}

void pahulja(){
    
    float j;
    for(j=0; j<=0.5; j+= 0.01){
        glPushMatrix();
        glTranslatef(0, 0, j);
        int i;
        for (i=0; i<6; i++){
            glPushMatrix();
            glRotatef(60*i, 0, 0,1);
            pahuljaDeo();
            glPopMatrix();
        }
        glPopMatrix();
    }
        
    
}




























