#include <stdlib.h>
#include "header.h"

void on_timer(int value){


    if (value != TIMER_ID)
        return;
    
    parametar_animacije++;

    //kretanje
    switch(smer_kretanja){
        case LEVO:
            _x += vektorX[0];
            _z += vektorX[1];
            break;
        case DESNO:
            _x -= vektorX[0];
            _z -= vektorX[1];
            break;
        case NAPRED:
            _z += vektorZ[1];
            _x += vektorZ[0];
            break;
            
        case NAZAD:
            _z -= vektorZ[1];
            _x -= vektorZ[0];
            break;
        default:
            break;
    }
    
    //rotiranje kamere
    switch(smer_rotiranja){
        case DESNO:
            _fi += 0.05;
            ugao -= 0.05;
            vektorX[0] = cos(ugao);
            vektorX[1] = -sin(ugao);
            vektorZ[0] = sin(ugao);
            vektorZ[1] = cos(ugao);
            break;
        case LEVO:
            _fi -= 0.05;
            ugao += 0.05;
            vektorX[0] = cos(ugao);
            vektorX[1] = -sin(ugao);
            vektorZ[0] = sin(ugao);
            vektorZ[1] = cos(ugao);
            break;
        default:
            break;
    }
    
    if(magija.aktivno){
        if(brojac < 50){
            brojac++; 
        } else {
            magija.x += magija.vec_x*1.5;
            magija.z += magija.vec_z*1.5;
            brojac++;
        }
    }
    
    if(kolizija2()){
        parametar_magije++;
    }
    
    switch(element){
        case VATRA: 
            if(parametar_magije == 8){
                magija.aktivno = 0;
            }
            break;
        case LED:
            if(parametar_magije == 50){
                magija.aktivno = 0;
            }
    }
    
    
    glutPostRedisplay();

    if (animacija_kretanja) {
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
}



