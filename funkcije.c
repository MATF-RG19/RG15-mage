#include "header.h"
#include "image.h"

void init_lights(){
    
    GLfloat light_position[] = { 0, 3, 3, 1 };

    
    float light_ambient[] = {.3f, .3f, .3f, 1};
    float light_diffuse[] = {.7f, .7f, .7f, 1};
    float light_specular[] = {.7f, .7f, .7f, 1};

    

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    /*GLfloat ambient[] = {0.3,0.3,0.3,0};
    GLfloat diffuse[] = {0,0.7,0,0};
    GLfloat specular[] = {0.6,0.6,0.6,0};
    GLfloat shininess = 80;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);*/
}


void initialize(void){ // preuzeto sa casa
    
    Image * image;

    
    //glClearColor(0, 0, 0, 0);

    
    //glEnable(GL_DEPTH_TEST);

    
    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

   
    image = image_init(0, 0);

   
    image_read(image, FILENAME0);

   
    glGenTextures(3, names);

    glBindTexture(GL_TEXTURE_2D, names[1]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    
    image_read(image, FILENAME1);

    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    
    image_read(image, FILENAME2);

    glBindTexture(GL_TEXTURE_2D, names[2]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

   
    glBindTexture(GL_TEXTURE_2D, 0);


    image_done(image);


}

void kolizija(void){
    
    if(_x <= -45){
        _x = -45;
    }
    if(_z <= -45){
        _z = -45;
    }
    if(_x >= 45){
        _x = 45;
    }
    if(_z >= 95){
        _z = 95;
    }
    
    if(_x >= -36 && _x <= -25 && _z >= -33.33){
        if(_z <= -23){
            _z = -23;
        }
    }
    
    if(_x >= -36 && _x <= -25 && _z <= -29.33){
        if(_z >= -35.5){
            _z = -35.5;
        }
    }
    
    if(_z >= -35 && _z <= -24 && _x <= -29.33){
        if(_x >= -37){
            _x = -37;
        }
    }
    
    if(_z >= -35 && _z <= -24 && _x >= -33.33){
        if(_x <= -24){
            _x = -24;
        }
    }
    //-31.33, -31.33
    
    if(_x >= -5 && _x <= 6 && _z >= -33.33){
        if(_z <= -23){
            _z = -23;
        }
    }
    
    if(_x >= -5 && _x <= 6 && _z <= -29.33){
        if(_z >= -35.5){
            _z = -35.5;
        }
    }
    
    if(_z >= -35 && _z <= -24 && _x <= 2){
        if(_x >= -6){
            _x = -6;
        }
    }
    
    if(_z >= -35 && _z <= -24 && _x >= -2){
        if(_x <= 7){
            _x = 7;
        }
    }
    
    // 0, -31.33
    
    //31.33
    if(_x <= 36 && _x >= 25 && _z >= -33.33){
        if(_z <= -23){
            _z = -23;
        }
    }
    
    if(_x <= 36 && _x >= 25 && _z <= -29.33){
        if(_z >= -35.5){
            _z = -35.5;
        }
    }
    
    if(_z >= -35 && _z <= -24 && _x >= 29.33){
        if(_x <= 37){
            _x = 37;
        }
    }
    
    if(_z >= -35 && _z <= -24 && _x <= 33.33){
        if(_x >= 24){
            _x = 24;
        }
    }
}

/*int kolizija2(float x, float y){
    
    if(x <= -45){
        return 1;
    }
    if(z <= -45){
        return 1;
    }
    if(x >= 45){
        return 1;
    }
    if(z >= 95){
        return 1;
    }
    
    if(x >= -36 && x <= -25 && z >= -33.33){
        if(z <= -23){
            return 1;
        }
    }
    
    if(_x >= -36 && _x <= -25 && _z <= -29.33){
        if(_z >= -35.5){
            _z = -35.5;
        }
    }
    
    if(_z >= -35 && _z <= -24 && _x <= -29.33){
        if(_x >= -37){
            _x = -37;
        }
    }
    
    if(_z >= -35 && _z <= -24 && _x >= -33.33){
        if(_x <= -24){
            _x = -24;
        }
    }
    //-31.33, -31.33
    
    if(_x >= -5 && _x <= 6 && _z >= -33.33){
        if(_z <= -23){
            _z = -23;
        }
    }
    
    if(_x >= -5 && _x <= 6 && _z <= -29.33){
        if(_z >= -35.5){
            _z = -35.5;
        }
    }
    
    if(_z >= -35 && _z <= -24 && _x <= 2){
        if(_x >= -6){
            _x = -6;
        }
    }
    
    if(_z >= -35 && _z <= -24 && _x >= -2){
        if(_x <= 7){
            _x = 7;
        }
    }
    
    // 0, -31.33
    
    //31.33
    if(_x <= 36 && _x >= 25 && _z >= -33.33){
        if(_z <= -23){
            _z = -23;
        }
    }
    
    if(_x <= 36 && _x >= 25 && _z <= -29.33){
        if(_z >= -35.5){
            _z = -35.5;
        }
    }
    
    if(_z >= -35 && _z <= -24 && _x >= 29.33){
        if(_x <= 37){
            _x = 37;
        }
    }
    
    if(_z >= -35 && _z <= -24 && _x <= 33.33){
        if(_x >= 24){
            _x = 24;
        }
    }
}*/



















