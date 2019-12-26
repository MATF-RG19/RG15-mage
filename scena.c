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
        glNormal3f(0, 0, -1);

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
    
        glNormal3f(1, 0, 0);
        
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
    
        glNormal3f(0, 0, -1);

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

void init_lights(){
    
    GLfloat light_position[] = { 0, 3, 3, 1 };

    
    float light_ambient[] = {.3f, .3f, .3f, 1};
    float light_diffuse[] = {.7f, .7f, .7f, 1};
    float light_specular[] = {.7f, .7f, .7f, 1};

    

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    /*GLfloat ambient[] = {0.3,0.3,0.3,0};
    GLfloat diffuse[] = {0,0.7,0,0};
    GLfloat specular[] = {0.6,0.6,0.6,0};
    GLfloat shininess = 80;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);*/
}


void initialize(void){ // preuzeto sa casa
    
    Image * image;

    
    //glClearColor(0, 0, 0, 0);

    
    //glEnable(GL_DEPTH_TEST);

    
    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

   
    image = image_init(0, 0);

   
    image_read(image, FILENAME0);

   
    glGenTextures(3, names);

    glBindTexture(GL_TEXTURE_2D, names[1]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    
    image_read(image, FILENAME1);

    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    
    image_read(image, FILENAME2);

    glBindTexture(GL_TEXTURE_2D, names[2]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

   
    glBindTexture(GL_TEXTURE_2D, 0);


    image_done(image);


}
















