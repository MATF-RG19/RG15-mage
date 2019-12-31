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
float _fi = PI/2;//*
float ugao = 0;
float vektorX[2] = {1, 0};//*
float vektorZ[2] = {0, 1};//*
int smer_kretanja = 0;
int smer_rotiranja = 0;
float parametar_animacije = 0;
int brojac = 0;
static float ugao2 = PI/2;
int element = 0;
int parametar_magije = 1;
static float tmpx;
static float tmpz;

Magija magija;

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
    
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    init_lights();
    
    glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    animacija_kretanja = 1;

    
    magija.aktivno = 0;
    
    glEnable(GL_COLOR_MATERIAL);
    
    initialize();
    
    glClearColor(0, 0, 0, 0);
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
    case 'k':
    case 'K':
        smer_rotiranja = DESNO;
        
        
        break;
    case 'j':
    case 'J':    
        smer_rotiranja = LEVO;
        
        break;
    case 'f':
    case 'F':
        if(!magija.aktivno){ //zapocinje animaciju pucanja
            if(element){
                brojac = 0;
                magija.aktivno = 1;
                magija.x = _x;
                magija.z = _z;
                parametar_magije = 1;
            }
        }
        break;
        
    case 'r':
    case 'R':
        if(!magija.aktivno){ //bira se magija u odnosu na to gde se nalazi lik
            if(_x > -33.33 && _x < -28.33 && _z > -26.33 && _z < -21.33){
                element = VATRA;
            } else if(_x > -1 && _x < 3 && _z > -26.33 && _z < -21.33){
                element = LED;
            } else if(_x > 31.33 && _x < 35.33 && _z > -26.33 && _z < -21.33){
                element = MUNJA;
            }
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
        if (smer_kretanja == NAPRED)
            smer_kretanja = 0;
        break;
        
    case 'a':
    case 'A':    
        if (smer_kretanja == LEVO)
            smer_kretanja = 0;
        break;
        
    case 's':
    case 'S':    
        if (smer_kretanja == NAZAD)
            smer_kretanja = 0;
        break;
        
    case 'd':
    case 'D':    
        if (smer_kretanja == DESNO)
            smer_kretanja = 0;
        break;
        
    case 'j':
    case 'J':    
        if (smer_rotiranja == LEVO)
            smer_rotiranja = 0;
        break;
        
    case 'k':
    case 'K':    
        if (smer_rotiranja == DESNO)
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

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            0.1, 200);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    kolizija1();
    
    gluLookAt(
            1+_x, 6.5, _z,
            1+_x + cos(_fi), 6.5, _z + sin(_fi),
            0, 1, 0
        );
    
    
    scena();
    
    //meta
    glPushMatrix();
    glTranslatef(0, 0, 50);
    glScalef(0.8, 0.8, 0.8);
    modelLika(1);
    glPopMatrix();
    
    
    glPushMatrix();
    //kretanje i rotiranje
    glTranslatef(1+_x, 0, 0+_z);
    glRotatef(-(_fi/PI*180-90), 0, 1, 0);
    modelLika(0);
    
    if(element){//pucanje ako je izabran neki element
        
        glPushMatrix();
        
        switch(element){ //boja kruga oko stapica
            case VATRA: glColor3f(1,0,0); break;
            case LED: glColor3f(0.4,0.4,1); break;
            case MUNJA: glColor3f(1,1,0); break;
            default: break;
        }
        
        //pozicioniranje kruga i njegova animacija
        glRotatef(5, 1, 0, 0);
        glRotatef(-5, 0, 0, 1);
        
        glTranslatef(-1.65, 5.6, 3);
        glRotatef(parametar_animacije/5, 0, 1, 0);
        glScalef(0.25, 1, 0.25);
        glTranslatef(0, -0.05, 0);
        magic_circle(0, 0);
        
        glPopMatrix();

    }
    glPopMatrix();
    
    //postavljanje modela munje
    glPushMatrix();
    glTranslatef(33.33, 6.5 + sin(parametar_animacije/50.0), -29.08);
    glRotatef(180, 0, 1,0);
    munja_model();
    glPopMatrix();
    
    //postavljanje modela vatre
    glPushMatrix();
    glTranslatef(-29.33, 7 + sin((parametar_animacije+50)/50.0), -29.58);
    vatra();
    glPopMatrix();
    
    //postavljanje modela pahulje
    glPushMatrix();
    glTranslatef(2, 6.5 + sin((parametar_animacije+100)/50.0), -29.58);
    glScalef(0.7, 0.7, 1);
    glTranslatef(0, 2, 0);
    pahulja();
    glPopMatrix();
    
    
    altar(-31.33, -31.33);
    altar(0, -31.33);
    altar(31.33, -31.33);
    
    glColor3f(1,1,1);
    magic_circle(-29.33, -24.33);
    magic_circle(2, -24.33);
    magic_circle(33.33, -24.33);
    
    //nalazi se na krugu za pucanje magija
    double clip_plane[] = {vektorZ[0], 0, vektorZ[1], -(vektorZ[0]*_x + vektorZ[1]*_z + 10)};
    glClipPlane(GL_CLIP_PLANE0, clip_plane);
    
    //odseca deo munje
    double clip_plane2[] = {-vektorZ[0], 0, -vektorZ[1], (vektorZ[0]*_x + vektorZ[1]*_z + sqrt(tmpx*tmpx + tmpz*tmpz))};
    glClipPlane(GL_CLIP_PLANE1, clip_plane2);
    
    
    if(brojac>=50 && magija.aktivno){
        
        if(element == MUNJA){
            if(brojac >= 70){
                magija.aktivno = 0;
            }
            
            /*izracunavaju se koordinate clipping regiona da bi se izracunala njegova udaljenost*/
            if(brojac == 50){
                tmpx = fabs(10*cos(_fi));
                tmpz = fabs(10*sin(_fi));
            }
            while(!kolizija2()){
                tmpx += fabs(magija.vec_x);
                tmpz += fabs(magija.vec_z);
                magija.x += magija.vec_x;
                magija.z += magija.vec_z;
            }
                    
            glEnable(GL_CLIP_PLANE1);
            glPushMatrix();
            
            glTranslatef(1+_x + 10*cos(_fi), 3, _z + 10*sin(_fi));
            glRotatef(ugao/PI*180, 0, 1, 0);
            munja();
            glPopMatrix();
            
            glDisable(GL_CLIP_PLANE1);
        } else {
            glPushMatrix();
                glEnable(GL_CLIP_PLANE0);
                
                //gasi clipping region kada se ledenica zaustavi
                if(kolizija2()){
                    glDisable(GL_CLIP_PLANE0);
                }
                
                //kretanje magija
                glTranslatef(magija.x+1, 3, magija.z);
                
                switch(element){
                    case VATRA:
                        glPushMatrix();
                        glColor3f(1,0,0);
                        glScalef(parametar_magije, parametar_magije, parametar_magije);
                        glutSolidSphere(1, 30, 30);
                        glPopMatrix();
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
        }
        
        glPointSize(3);
        glLineWidth(5);
        if(brojac < 70)
            magic_circle2(1+_x + 10*cos(_fi), _z + 10*sin(_fi));
        
        glPointSize(1);
        glLineWidth(1);
        if(kolizija2()){
            magija.vec_x = 0;
            magija.vec_z = 0;
        }
    } else if(magija.aktivno){/*animacija povecavanja kruga i pampte se odgovarajuce vrednosti koje se koriste za pucanje magije*/
        glPointSize(3);
        glLineWidth(5);
        magic_circle2(1+_x + 10*cos(_fi), _z + 10*sin(_fi));
        glPointSize(1);
        glLineWidth(1);
        
        magija.x = _x + 10*cos(_fi);;
        magija.z = _z + 10*sin(_fi);
        magija.vec_x = vektorZ[0];
        magija.vec_z = vektorZ[1];
        ugao2 = _fi;
    }
       
    glutSwapBuffers();
}



