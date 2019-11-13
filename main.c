#include <stdlib.h>
#include <math.h>
#include "funkcije.h"
#define PI 3.1415926535

static int window_width, window_height;

static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);

static float _x = 0;
static float _z = 0;
static float _fi = 0;



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

    glClearColor(0.75, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);

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
        _x -= 1;
        glutPostRedisplay();
        break;
    case 'a':
        _x += 1;
        glutPostRedisplay();
        break;
    case 'w':
        _z += 1;
        glutPostRedisplay();
        break;
    case 's':
        _z -= 1;
        glutPostRedisplay();
        break;
    case 'e':
        _fi += 0.05;
        glutPostRedisplay();
        break;
    case 'q':
        _fi -= 0.05;
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

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            0.1, 200);

   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            0+_x, 6, 1+_z,
            0+_x + cos(2*PI*_fi), 6, 2+_z + sin(2*PI*_fi),
            0, 1, 0
        );

    glPushMatrix();
    glTranslatef(1+_x, 0, 0+_z);
    modelLika();
    glPopMatrix();
    
    scena();
    
    
    
    
    //ose
    
    /*glColor3f(1, 0, 0);
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
