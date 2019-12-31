#include <stdlib.h>
#include "header.h"

void modelLika(void){
    
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
    /*glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(0, 6, 0.5);
    glutSolidCube(1);
    
    glColor3f(0, 0, 0);
    glutWireCube(1);
    glPopMatrix();*/
    
        
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
    
    //stapic
    glPushMatrix();
    
    glRotatef(5, 1, 0, 0);
    glRotatef(-5, 0, 0, 1);
    
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-1.7, 4, 3);
    glScalef(0.3, 1.6, 0.3);
    glTranslatef(0, 0.5, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    
    
    glPushMatrix();
    
    glColor3f(1,1,1);
    glTranslatef(-1.7, 5.6, 3);
    glScalef(0.3, 0.4, 0.3);
    glTranslatef(0, 0.5, 0.5);
    glutSolidCube(1);
    
    glPopMatrix();
    
    
    glPopMatrix();
}

void altar(float x, float z){
    
    glPushMatrix();
    
    glTranslatef(2+x, 0, 2+z);
    
    //postolje
    glPushMatrix();
        glScalef(1, 0.25, 1);
        glTranslatef(0, 2, 0);
        glColor3f(0.8,0.8,0.8);
        glutSolidCube(4);

    glPopMatrix();
    
    
    //stub
    glPushMatrix();
    
        glTranslatef(0, 1, 0);
        glScalef(3, 3, 3);        
        glTranslatef(0, 0.5, 0);
        
        glColor3f(0.8,0.8,0.8);
        glutSolidCube(1);
        

    
    glPopMatrix();
    
    
    //vrh
    glPushMatrix();
    
        glTranslatef(0, 4, 0);
        glScalef(1, 0.25, 1);
        glTranslatef(0, 2, 0);
        glColor3f(0.8,0.8,0.8);
        glutSolidCube(4);

    glPopMatrix();
    
    
    glPopMatrix();
    
}

void munja_model(void){
    
    
    
    glPushMatrix();

    glScalef(0.5,0.5,1);
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        
        glVertex3f(0,3,0);
        
        glVertex3f(0,3,0.5);
        
        glVertex3f(-1,3,0.5);
        
        glVertex3f(-1,3,0);
    glEnd();
    
    
    
    glBegin(GL_POLYGON);
        glNormal3f(-1,1,0);
        
        glVertex3f(-1,3,0);
        
        glVertex3f(-1,3,0.5);
        
        glVertex3f(0,0,0.5);
        
        glVertex3f(0,0,0);
        
    glEnd();
    
   
    
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        
        glVertex3f(0,0,0);
        
        glVertex3f(0,2,0);
        
        glVertex3f(0,2,0.5);
        
        glVertex3f(0,0,0.5);
    glEnd();
    
    
    
    glBegin(GL_POLYGON);
        glNormal3f(0,-1,0);
        
        glVertex3f(1,2,0);
        
        glVertex3f(0,2,0);
        
        glVertex3f(0,2,0.5);
        
        glVertex3f(1,2,0.5);
    glEnd();
    
    
    
    
    glBegin(GL_POLYGON);
    
        glNormal3f(-1,-1,0);

        glVertex3f(0,5,0);
        
        glVertex3f(1,2,0);
        
        glVertex3f(1,2,0.5);
        
        glVertex3f(0,5,0.5);
    glEnd();
    
    
    glBegin(GL_POLYGON);
        glNormal3f(1,0,0);
        
        glVertex3f(0,5,0);
        
        glVertex3f(0,3,0);
        
        glVertex3f(0,3,0.5);
        
        glVertex3f(0,5,0.5);
    glEnd();

    
   
    
    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        glVertex3f(0,3,0);
        glVertex3f(-1,3,0);
        glVertex3f(0,0,0);
        glVertex3f(0,2,0);
        glVertex3f(1,2,0);
        glVertex3f(0,5,0);
    glEnd();
    
    
 
    
    
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glBegin(GL_POLYGON);
        
        glNormal3f(0,0,1);
        
        glVertex3f(0,3,0);
        
        glVertex3f(0,5,0);
        
        glVertex3f(1,2,0);
        
        glVertex3f(0,2,0);
        
        glVertex3f(0,0,0);
        
        glVertex3f(-1,3,0);
    glEnd();
    
    
   
    glPopMatrix();
    
    glPopMatrix();
}

void vatraDeo(float x){
    int i;
    glBegin(GL_POLYGON);
    glColor3f(1,x,0);
    for(i=0; i < NUMBER_OF_DOTS; i++){
        glVertex3f(cos(PI + i*PI/NUMBER_OF_DOTS),
                   sin(PI + i*PI/NUMBER_OF_DOTS),
                   0);
        
    }
    for(i=0; i < NUMBER_OF_DOTS; i++){
        glVertex3f(-1.5 + 2.5*cos(i*PI/3.4/NUMBER_OF_DOTS),
                   2.5*sin(i*PI/NUMBER_OF_DOTS/3.4),
                   0);
    }
    for(i=0; i < NUMBER_OF_DOTS; i++){
        glVertex3f(1.5 + 2.5*cos(i*PI/3.4/NUMBER_OF_DOTS+PI-PI/3.4),
                   2.5*sin(i*PI/NUMBER_OF_DOTS/3.4+PI-PI/3.4),
                   0);
        
    }
    glEnd();
}

void vatra(void){
    
    glPushMatrix();
     
    glTranslatef(0,0.5,0);
    
    int i;

    //omotac
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i=0; i<NUMBER_OF_DOTS; i++){
        glVertex3f(cos(PI + i*PI/NUMBER_OF_DOTS),
                sin(PI + i*PI/NUMBER_OF_DOTS),
                0);
        glVertex3f(cos(PI + i*PI/NUMBER_OF_DOTS),
                sin(PI + i*PI/NUMBER_OF_DOTS),
                0.5);
    }
    for(i=0; i<NUMBER_OF_DOTS; i++){
        glVertex3f(-1.5 + 2.5*cos(i*PI/3.4/NUMBER_OF_DOTS),
                2.5*sin(i*PI/NUMBER_OF_DOTS/3.4),
                0);
        glVertex3f(-1.5 + 2.5*cos(i*PI/3.4/NUMBER_OF_DOTS),
                2.5*sin(i*PI/NUMBER_OF_DOTS/3.4),
                0.5);
    }
    for(i=0; i<NUMBER_OF_DOTS; i++){
        glVertex3f(1.5 + 2.5*cos(i*PI/3.4/NUMBER_OF_DOTS + PI - PI/3.45),
                2.5*sin(i*PI/NUMBER_OF_DOTS/3.4 + PI - PI/3.45),
                0);
        glVertex3f(1.5 + 2.5*cos(i*PI/3.4/NUMBER_OF_DOTS+PI-PI/3.45),
                2.5*sin(i*PI/NUMBER_OF_DOTS/3.4+PI-PI/3.45),
                0.5);
    }
            
    glEnd(); 

    
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

void pahuljaDeo(void){
    

    glColor3f(0.4,0.4,1);
    glPushMatrix();
    
    glScalef(0.4, 2, 0.5);
    glTranslatef(0,0.5,0);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(50, 0, 0, 1);
    glScalef(0.3, 1, 0.5);
    glTranslatef(0,0.5,0);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(-50, 0, 0, 1);
    glScalef(0.3, 1, 0.5);
    glTranslatef(0,0.5,0);
    glutSolidCube(1);
    glPopMatrix();
    
    
}

void pahulja(void){
    
    int i;
    for (i=0; i<6; i++){
        glPushMatrix();
        glRotatef(60*i, 0, 0,1);
        pahuljaDeo();
        glPopMatrix();
    }
}

void magic_circle(float x, float z){
    
    glDisable(GL_LIGHTING);
    glPushMatrix();
    
    glTranslatef(x, 0, z);
    
    int i;
    for(i=0; i < NUMBER_OF_DOTS; i++){
        
        glBegin(GL_POINTS);
        glVertex3f(2*cos(i*2*PI/NUMBER_OF_DOTS),
                   0.05,
                   2*sin(i*2*PI/NUMBER_OF_DOTS));

        glVertex3f(1.7*cos(i*2*PI/NUMBER_OF_DOTS),
                   0.05,
                   1.7*sin(i*2*PI/NUMBER_OF_DOTS));
        glEnd();
    }
    
    glBegin(GL_LINE_LOOP);
        glVertex3f(0, 0.05, 2);
        glVertex3f(-2, 0.05, 0);
        glVertex3f(0, 0.05, -2);
        glVertex3f(2, 0.05, 0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
        glVertex3f(-1, 0.05, 1);
        glVertex3f(-1, 0.05, -1);
        glVertex3f(1, 0.05, -1);
        glVertex3f(1, 0.05, 1);
    glEnd();
    glPopMatrix();
    
    glEnable(GL_LIGHTING);
}


void magic_circle2(float x, float z){
    
    glDisable(GL_LIGHTING);
    glPushMatrix();
    
    glTranslatef(x, 3, z);
    glRotatef(-(_fi/PI*180-90), 0, 1, 0);
    glRotatef(90, 1, 0, 0);
    if(brojac <= 50){
        glScalef(brojac/50.0, 1, brojac/50.0);
    }
    int i;
    for(i=0; i < NUMBER_OF_DOTS; i++){
        glColor3f(1,1,1);
        glBegin(GL_POINTS);
        glVertex3f(2*cos(i*2*PI/NUMBER_OF_DOTS),
                   0.05,
                   2*sin(i*2*PI/NUMBER_OF_DOTS));

        glVertex3f(1.7*cos(i*2*PI/NUMBER_OF_DOTS),
                   0.05,
                   1.7*sin(i*2*PI/NUMBER_OF_DOTS));
        glEnd();
    }
    
    glBegin(GL_LINE_LOOP);
        glVertex3f(0, 0.05, 2);
        glVertex3f(-2, 0.05, 0);
        glVertex3f(0, 0.05, -2);
        glVertex3f(2, 0.05, 0);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
        glVertex3f(-1, 0.05, 1);
        glVertex3f(-1, 0.05, -1);
        glVertex3f(1, 0.05, -1);
        glVertex3f(1, 0.05, 1);
    glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

void led(void){
    
    glColor3f(0.4, 0.4, 1);
    
    glPushMatrix();
    
    glTranslatef(0, 0, 0);
    glRotatef(-90, 1, 0, 0);
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(0.5,2,30,30);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glutSolidCone(0.5,2,30,30);
    glPopMatrix();
    glPopMatrix();
}

void munjaDeo(void){
    
    glDisable(GL_LIGHTING);
    glLineWidth(5);
    glColor3f(1,1,0);
    glPushMatrix();
    
    //glTranslatef(0, 3, 0);
    glRotatef(40, 0, 0, 1);
    glBegin(GL_LINE_STRIP);
        glVertex3f(0, 0, 0);
        glVertex3f(0, -1, 1);
        glVertex3f(0, 2, 3);
        glVertex3f(0, -2, 6);
        glVertex3f(0, 2, 10);
        glVertex3f(0, 0, 12);
        glVertex3f(0, 1, 13);
        glVertex3f(0, -1, 15);
        glVertex3f(0, 0, 16);
    glEnd();
    
    glPopMatrix();
    
    glLineWidth(1);
    glEnable(GL_LIGHTING);
}

void munja(void){
    int i;
    glPushMatrix();
    for(i=0; i<9; i++){
        glTranslatef(0, 0, 16);
        munjaDeo();
    }
    glPopMatrix();
    munjaDeo();
}

















