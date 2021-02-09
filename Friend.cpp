#include "Friend.h"

Friend::Friend(Sprite *sprite):Player_Osnova(sprite){
    sprite->set_speed(1);
}



void Friend::trazi_point(){

    sprite->setState(Sprite::STOP);
    int x=sprite->spriteRect->x,y=sprite->spriteRect->y;
    int xp[3],yp[3];

    for(int i=0;i<3;i++){
        xp[i]=p1[i]->spriteRect->x;
        yp[i]=p1[i]->spriteRect->y;
    }
    float rast[3];
    for(int i=0;i<3;i++){
        rast[i]=sqrt((xp[i]-x)*(xp[i]-x)+(yp[i]-y)*(yp[i]-y));
    }


    int najmanji=0;
    float min=rast[0];
    for(int i=0;i<3;i++){
        if(rast[i]<min){
            min=rast[i];
            najmanji=i;
        }
    }

    if(x<xp[najmanji]){
        sprite->setState(sprite->getState()|Sprite::RIGHT);
    }
     if(x > xp[najmanji]){
        sprite->setState(sprite->getState()|Sprite::LEFT);
    }

    if(y<yp[najmanji]){
      sprite->setState(sprite->getState()|Sprite::DOWN);
    }
     if(y>yp[najmanji]){
        sprite->setState(sprite->getState()|Sprite::UP);
    }
}

