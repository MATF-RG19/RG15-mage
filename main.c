#include <stdlib.h>
#include "funkcije.h"


static int window_width, window_height;

static void on_keyboard(unsigned char key, int x, int y);
static void on_keyboard_up(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);

float _x = 0;
float _z = 0;
int animacija_kretanja;
int animacija_rotiranja;
float _fi = PI/2;
float ugao = 0;
float vektorX[2] = {1, 0};
float vektorZ[2] = {0, 1};
int smer_kretanja = 0;
int smer_rotiranja = 0;






int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glutKeyboardFunc(on_keyboard);
    glutKeyboardUpFunc(on_keyboard_up);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    
    animacija_kretanja = 0;
    animacija_rotiranja = 0;

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    
    
    if (!animacija_kretanja) {
            glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
            animacija_kretanja = 1;
        }
    
    
    /*glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/
    
    
    //glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    
    


    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        
    case 27:
        exit(0);
        break;
        
    case 'd':
        smer_kretanja = DESNO;
        
        break;
    case 'a':
        smer_kretanja = LEVO;
        
        
        break;
    case 'w':
        smer_kretanja = NAPRED;
        
        break;
    case 's':
        smer_kretanja = NAZAD;
        
        break;
    case 'e':
        smer_rotiranja = DESNO;
        
        
        break;
    case 'q':
        smer_rotiranja = LEVO;
        
        break;
    case 'x':
        animacija_kretanja = 0;
        animacija_rotiranja = 0;
        break;
    }
}

static void on_keyboard_up(unsigned char key, int x, int y){
    switch(key){
    case 27:
        exit(0);
        break;
    case 'w':
        smer_kretanja = 0;
        break;
        
    case 'a':
        smer_kretanja = 0;
        break;
        
    case 's':
        smer_kretanja = 0;
        break;
        
    case 'd':
        smer_kretanja = 0;
        break;
        
    case 'q':
        smer_rotiranja = 0;
        break;
        
    case 'e':
        smer_rotiranja = 0;
        break;
        
    default:
        break;
    }
}


static void on_reshape(int width, int height)
{
    window_width = width;
    window_height = height;


}

static void on_display(void)
{
     
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, window_width, window_height);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            0.1, 200);

    gluLookAt(
            1+_x, 7, 0+_z,
            1+_x + cos(_fi), 7, 0+_z + sin(_fi),
            0, 1, 0
        );
    

    //init_lights();
    
    
    scena();
    

    glPushMatrix();
    glTranslatef(1+_x, 0, 0+_z);
    glRotatef(-(_fi/PI*180-90), 0, 1, 0);
    modelLika();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(33.33, 6, -29.08);
    glRotatef(180, 0, 1,0);
    munja();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-29.33, 6.5, -29.58);
    vatra();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(2, 6, -29.58);
    glScalef(0.7, 0.7, 1);
    glTranslatef(0, 2, 0);
    pahulja();
    glPopMatrix();
    
    
    
    
    altar(-31.33, -31.33);
    altar(0, -31.33);
    altar(31.33, -31.33);
    
    
    
    
    
    
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


void init_lights(){
    
    GLfloat light_position[] = { 0, 15, 50, 1 };

    
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1 };

    
    GLfloat light_diffuse[] = { 0.7, 0.7, 0.7, 1 };

    
    GLfloat light_specular[] = { 0.9, 0.9, 0.9, 1 };

    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}
