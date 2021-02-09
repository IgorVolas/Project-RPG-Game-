#ifndef ENEMIE_H_INCLUDED
#define ENEMIE_H_INCLUDED
#include "sprite.h"
#include "Point.h"
#include "Player_Osnova.h"
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <fstream>
#include <sstream>
using namespace std;

class Friend: public Player_Osnova{
public:
    Point *p1[3];
    int poeni;
    Friend(Sprite *sprite);
    void looking_for_point(Point *pp1,Point *pp2,Point *pp3){
        p1[0]=pp1;
        p1[1]=pp2;
        p1[2]=pp3;
    }


    void trazi_point();
    void setState(short a){sprite->setState(a);}
};


#endif // ENEMIE_H_INCLUDED
