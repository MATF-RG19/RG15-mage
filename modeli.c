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
    
    /*GLfloat material_ambient[] = { 0.5, 0.5, 0.5, 1 };
    GLfloat material_diffuse[] = { 0.8, 0.8, 0.8, 1 };
    GLfloat material_specular[] = { 0, 0, 0, 1 };
    GLfloat shininess = 20;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT_AND_BACK,  GL_SHININESS, shininess);*/
    
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

void munja(void){
    
    
    
    glPushMatrix();
    
    
    /*GLfloat material_ambient[] = { 0.3, 0.3, 0.3, 1 };
    GLfloat material_diffuse[] = { 1, 1, 0.4, 1 };
    GLfloat material_specular[] = { 0, 0, 0, 1 };
    GLfloat shininess = 20;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT_AND_BACK,  GL_SHININESS, shininess);*/
    
    
    glScalef(0.5,0.5,1);
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
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
    
   
    
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
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
    
    
    
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(0,5,0);
        glVertex3f(0,2,0);
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
    
   
    
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
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
        /*glVertex3f(0,3,0);
        glVertex3f(-1,3,0);
        glVertex3f(0,0,0);
        glVertex3f(0,2,0);
        glVertex3f(1,2,0);
        glVertex3f(0,5,0);*/
        
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

void vatra(void){
    
    
    glPushMatrix();
    
    
    /*GLfloat material_ambient[] = { 0.3, 0.3, 0.3, 1 };
    GLfloat material_diffuse[] = { 1, 0.4, 0.4, 1 };
    GLfloat material_specular[] = { 0, 0, 0, 1 };
    GLfloat shininess = 20;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT_AND_BACK,  GL_SHININESS, shininess);*/
    
    
    
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

void pahuljaDeo(void){
    
    
    
    /*glColor3f(0.4,0.4,1);
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
    
    glPopMatrix();*/
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
    
    /*glPushMatrix();
    
    GLfloat material_ambient[] = { 0.3, 0.3, 0.3, 1 };
    GLfloat material_diffuse[] = { 0.4, 0.4, 1, 1 };
    GLfloat material_specular[] = { 0, 0, 0, 1 };
    GLfloat shininess = 20;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT_AND_BACK,  GL_SHININESS, shininess);
    
    
    
    
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
     
     
    glPopMatrix();*/
    
    //glPushMatrix();
    int i;
        for (i=0; i<6; i++){
            glPushMatrix();
            glRotatef(60*i, 0, 0,1);
            pahuljaDeo();
            glPopMatrix();
        }
    //glPopMatrix();
    
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

















