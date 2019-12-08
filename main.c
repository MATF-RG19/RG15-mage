#include <stdlib.h>
#include "funkcije.h"


static int window_width, window_height;

static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);

static float _x = 0;
static float _z = 0;
static float _fi = PI/2;
static float ugao = 0;
static float vektorX[2] = {1, 0};
static float vektorZ[2] = {0, 1};




int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    
    
    /*glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/
    
    
    //glEnable(GL_NORMALIZE);
    //glEnable(GL_COLOR_MATERIAL);
    
    


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
        _x -= vektorX[0];
        _z -= vektorX[1];
        glutPostRedisplay();
        break;
    case 'a':
        _x += vektorX[0];
        _z += vektorX[1];
        glutPostRedisplay();
        break;
    case 'w':
        _z += vektorZ[1];
        _x += vektorZ[0];
        glutPostRedisplay();
        break;
    case 's':
        _z -= vektorZ[1];
        _x -= vektorZ[0];
        glutPostRedisplay();
        break;
    case 'e':
        _fi += 0.05;
        ugao -= 0.05;
        vektorX[0] = cos(ugao);
        vektorX[1] = -sin(ugao);
        vektorZ[0] = sin(ugao);
        vektorZ[1] = cos(ugao);
        glutPostRedisplay();
        break;
    case 'q':
        _fi -= 0.05;
        ugao += 0.05;
        vektorX[0] = cos(ugao);
        vektorX[1] = -sin(ugao);
        vektorZ[0] = sin(ugao);
        vektorZ[1] = cos(ugao);
        glutPostRedisplay();
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
    

    init_lights();
    
    
    scena();
    

    glPushMatrix();
    glTranslatef(1+_x, 0, 0+_z);
    glRotatef(-(_fi/PI*180-90), 0, 1, 0);
    modelLika();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(33.33, 6, -29.08);
    //glRotatef(180, 0, 1,0);
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
    
    GLfloat light_position[] = { 1, 10, 25, 0 };

    
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
