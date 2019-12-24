#include <stdlib.h>
#include "header.h"

void on_timer(int value){


    if (value != TIMER_ID)
        return;
    
    parametar_animacije++;

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
    
    if(niz.aktivno){
        if(brojac < 50){
            brojac++; 
        } else {
            niz.x += niz.vec_x*1.5;
            niz.z += niz.vec_z*1.5;
            brojac++;
        }
    }
    
    if(niz.z > 100){
        niz.aktivno = 0;
    }
    
    
    glutPostRedisplay();

    if (animacija_kretanja) {
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
}

/*void on_timer_magija (int value){
    if (value != TIMER_MAGIJA_ID)
        return;
    
    int i;
    for(i = 0; i<100000000; i++);

    if (animacija_magija) {
        glutTimerFunc(TIMER_INTERVAL, on_timer_magija, TIMER_MAGIJA_ID);
    }
}*/


