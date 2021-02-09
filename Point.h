#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <fstream>
#include "sprite.h"
#include "player.h"


#include <math.h>
#include <time.h>
using namespace std;

class Point:public Sprite{
private:
    static int poeni;
    bool pojeo;
    int vrednost;

public:
    Point(SpriteSheet *sheet,int vvrednost = 1,int w=32,int h=32 );
    void draw(SDL_Renderer * renderer);
    void move();
    void move(int dx,int dy);
    int pokupio(Player_Osnova *plajer);
    int random_od_0_do_n(int n);
    void razmesti(Point *p1);
    virtual ~Point(){}
};


#endif // POINT_H_INCLUDED
