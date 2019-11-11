#include <stdlib.h>
#include "funkcije.h"

/* Dimenzije prozora */
static int window_width, window_height;

/* Deklaracije callback funkcija. */
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);

static float _x = 0;
static float _z = 0;



int main(int argc, char **argv)
{
    /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    /* Kreira se prozor. */
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    /* Registruju se callback funkcije. */
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0.75, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);

    /* Program ulazi u glavnu petlju. */
    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        
    case 27:
        /* Zavrsava se program. */
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
    }
}

static void on_reshape(int width, int height)
{
    /* Pamte se sirina i visina prozora. */
    window_width = width;
    window_height = height;
}

static void on_display(void)
{
    /* Brise se prethodni sadrzaj prozora. */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Podesava se viewport. */
    glViewport(0, 0, window_width, window_height);

    /* Podesava se projekcija. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            0.1, 200);

    /* Podesava se tacka pogleda. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            0+_x, 4, 10+_z,
            0+_x, 2, 0+_z,
            0, 1, 0
        );

    glPushMatrix();
    glTranslatef(1+_x, 0, 0+_z);
    modelLika();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 50, 0);
    glutWireCube(100);
    glPopMatrix();
    
    
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
    


    /* Nova slika se salje na ekran. */
    glutSwapBuffers();
}
