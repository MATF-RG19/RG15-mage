#include <stdlib.h>
#include "funkcije.h"

void on_timer(int value){


    if (value != TIMER_ID)
        return;

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
    
    
    glutPostRedisplay();

    if (animacija_kretanja) {
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
}


