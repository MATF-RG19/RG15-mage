#ifndef _FUNKCIJE_H
#define _FUNKCIJE_H


#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926535
#define NUMBER_OF_DOTS 500
#define TIMER_ID 0
#define TIMER_MAGIJA_ID 1
#define TIMER_INTERVAL 30
#define LEVO 1
#define DESNO 2
#define NAPRED 3
#define NAZAD 4

//funkcije--------------------------------

void modelLika();
void scena();
void altar(float x, float z);
void munja();
void vatra();
void vatraDeo(float x);
void pahuljaDeo();
void pahulja();
void init_lights();
void on_timer(int value);
void magic_circle(float x, float z);
void magic_circle2(float x, float z);
void on_timer_magija(int value);
void lopta();


//promenljive-----------------------------

extern float _x;
extern float _z;
extern int animacija_kretanja;
extern int animacija_magija;
extern float _fi;
extern float ugao;
extern float vektorX[2];
extern float vektorZ[2];
extern int smer_kretanja;
extern int smer_rotiranja;
extern float parametar_animacije;
extern int brojac;


typedef struct Magija {
    int aktivno;
    float x;
    float z;
    float vec_x;
    float vec_z;
}Magija;

extern Magija niz;


#endif