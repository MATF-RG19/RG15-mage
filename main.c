#include <stdlib.h>
#include "header.h"
#include "image.h"


static int window_width, window_height;

static void on_keyboard(unsigned char key, int x, int y);
static void on_keyboard_up(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);

float _x = 0;
float _z = 0;
int animacija_kretanja = 0;
int animacija_magija = 0;
float _fi = PI/2;
float ugao = 0;
float vektorX[2] = {1, 0};
float vektorZ[2] = {0, 1};
int smer_kretanja = 0;
int smer_rotiranja = 0;
float parametar_animacije = 0;
int brojac = 0;
static float ugao2 = PI/2;
static int element = 0;

Magija niz;

GLuint names[3];




int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glutKeyboardFunc(on_keyboard);
    glutKeyboardUpFunc(on_keyboard_up);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    
    //glClearColor(0, 0, 0, 0);
    //glEnable(GL_DEPTH_TEST);
    
    
    
    glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    animacija_kretanja = 1;

    
    niz.aktivno = 0;
    /*glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/
    
    
    //glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    //glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
    
    
    initialize();

    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y){
    switch (key) {
        
    case 27:
        exit(0);
        break;
        
    case 'd':
    case 'D':
        smer_kretanja = DESNO;
        
        break;
    case 'a':
    case 'A':
        smer_kretanja = LEVO;

        break;
    case 'w':
    case 'W':    
        smer_kretanja = NAPRED;
        
        break;
    case 's':
    case 'S':
        smer_kretanja = NAZAD;
        
        break;
    case 'e':
    case 'E':
        smer_rotiranja = DESNO;
        
        
        break;
    case 'q':
    case 'Q':    
        smer_rotiranja = LEVO;
        
        break;
    case 'f':
    case 'F': 
        if(element){
            brojac = 0;
            niz.aktivno = 1;
            niz.x = _x;
            niz.z = _z;
        }
        break;
        
    case 'r':
    case 'R':
        if(_x > -31.33 && _x < -27.33 && _z > -26.33 && _z < -22.33){
            element = VATRA;
        } else if(_x > 0 && _x < 4 && _z > -26.33 && _z < -22.33){
            element = LED;
        }
    }
}

static void on_keyboard_up(unsigned char key, int x, int y){
    switch(key){
    case 27:
        exit(0);
        break;
    case 'w':
    case 'W':    
        smer_kretanja = 0;
        break;
        
    case 'a':
    case 'A':    
        smer_kretanja = 0;
        break;
        
    case 's':
    case 'S':    
        smer_kretanja = 0;
        break;
        
    case 'd':
    case 'D':    
        smer_kretanja = 0;
        break;
        
    case 'q':
    case 'Q':    
        smer_rotiranja = 0;
        break;
        
    case 'e':
    case 'E':    
        smer_rotiranja = 0;
        break;
        
    default:
        break;
    }
}


static void on_reshape(int width, int height){
    window_width = width;
    window_height = height;


}

static void on_display(void){
     
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, window_width, window_height);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            0.1, 200);

    gluLookAt(
            1+_x, 6.5, _z,
            1+_x + cos(_fi), 6.5, _z + sin(_fi),
            0, 1, 0
        );
    

    //init_lights();

    
    scena();
    

    glPushMatrix();
    glTranslatef(1+_x, 0, 0+_z);
    glRotatef(-(_fi/PI*180-90), 0, 1, 0);
    modelLika();
    
    if(element){
        
        
        glPushMatrix();
        
        switch(element){
            case VATRA: glColor3f(1,0,0); break;
            case LED: glColor3f(0.4,0.4,1); break;
            case MUNJA: glColor3f(1,1,0); break;
            default: break;
        }
        
        glRotatef(5, 1, 0, 0);
        glRotatef(-5, 0, 0, 1);
        
        glTranslatef(-1.65, 5.6, 3);
        glRotatef((parametar_animacije)/5, 0, 1, 0);
        glScalef(0.25, 1, 0.25);
        glTranslatef(0, -0.05, 0);
        magic_circle(0, 0);
        
        glPopMatrix();

    }
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(33.33, 6.5 + sin(parametar_animacije/50.0), -29.08);
    glRotatef(180, 0, 1,0);
    munja();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-29.33, 7 + sin((parametar_animacije+50)/50.0), -29.58);
    vatra();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(2, 6.5 + sin((parametar_animacije+100)/50.0), -29.58);
    glScalef(0.7, 0.7, 1);
    glTranslatef(0, 2, 0);
    pahulja();
    glPopMatrix();
    
    
    //kvadrat
    /*glPushMatrix();
    
    glTranslatef(-29.33, 0 , -24.33);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(2,0.2,2);
        glVertex3f(2,0.2,-2);
        glVertex3f(-2,0.2,-2);
        glVertex3f(-2,0.2,2);
    
    glEnd();
    glPopMatrix();*/
    
    
    altar(-31.33, -31.33);
    altar(0, -31.33);
    altar(31.33, -31.33);
    
    glColor3f(1,1,1);
    magic_circle(-29.33, -24.33);
    magic_circle(2, -24.33);
    magic_circle(33.33, -24.33);
    
    double clip_plane[] = {vektorZ[0], 0, vektorZ[1], -(vektorZ[0]*_x+vektorZ[1]*_z+10)};

    glClipPlane(GL_CLIP_PLANE0, clip_plane);
    
    
    
    if(brojac>=50 && niz.aktivno){
        glPushMatrix();
            glEnable(GL_CLIP_PLANE0);
            glTranslatef(niz.x+1 + 10*cos(_fi), 3, niz.z + 10*sin(_fi));
            
            switch(element){
                case VATRA:
                    glColor3f(1,0,0);
                    glutSolidSphere(1, 30, 30);
                    break;
                    
                case LED:
                    glRotatef(-(ugao2/PI*180-90), 0, 1, 0);
                    led();
                    break;
                    
                default:
                    break;
            }
            
            glDisable(GL_CLIP_PLANE0);
        glPopMatrix();
        glPointSize(3);
        glLineWidth(5);
        if(brojac < 70)
            magic_circle2(1+_x + 10*cos(_fi), _z + 10*sin(_fi));
        
        glPointSize(1);
        glLineWidth(1);
    } else if(niz.aktivno){
        glPointSize(3);
        glLineWidth(5);
        magic_circle2(1+_x + 10*cos(_fi), _z + 10*sin(_fi));
        glPointSize(1);
        glLineWidth(1);
        niz.x = _x;
        niz.z = _z;
        niz.vec_x = vektorZ[0];
        niz.vec_z = vektorZ[1];
        ugao2 = _fi;
    }
    
    
    
    
    //ose
    
   /* glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(10000, 0, 0);
    glEnd();
    
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 10000, 0);
    glEnd();
    
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 10000);
    glEnd();*/
    


    
    glutSwapBuffers();
}



