#include "Point.h"

int Point::poeni=0;

Point::Point(SpriteSheet *sheet, int vvrednost,int width, int height ):Sprite(sheet,width,height){
    pojeo=false;
    spriteRect->x=(random_od_0_do_n(8)+1)*32;
    spriteRect->y=(random_od_0_do_n(18)+1)*32;

    vrednost = vvrednost;

}

void Point::draw(SDL_Renderer * renderer){
    sheet->drawFrame("walk_down",0,spriteRect,renderer);
}

void Point::move(){}
void Point::move(int dx,int dy){}

int Point::pokupio(Player_Osnova *plajer){
    int x1=plajer->sprite->spriteRect->x;
    int x2=spriteRect->x-20;

    int y1=plajer->sprite->spriteRect->y;
    int y2=spriteRect->y-20;


    if(abs(x1-x2)<32 && abs(y1-y2)<32){
        int x_r=(random_od_0_do_n(8)+1)*32;
        int y_r=(random_od_0_do_n(18)+1)*32;
        int x_b= spriteRect->x;
        int y_b=spriteRect->y;
        spriteRect->x=x_r;
        spriteRect->y=y_r;

        if(abs(x_b-spriteRect->x) < 5 && abs(y_b-spriteRect->y) < 5){
            return poeni;
        }
            poeni += vrednost;
    }
    return poeni;

}

void Point::razmesti(Point *p2){
    int i=0;
   while(abs(spriteRect->x-p2->spriteRect->x)<32 && abs(spriteRect->y - p2->spriteRect->y)<32 ){

        spriteRect->x=p2->spriteRect->x+random_od_0_do_n(10)*32;
        spriteRect->y=p2->spriteRect->y+random_od_0_do_n(20)*32;
        if (spriteRect->x < 0 +5 ){
            spriteRect->x = 32;
        }else if (spriteRect->x > 32*9 - 5){
            spriteRect->x = 32*8;
        }
        if ( spriteRect->y < 0 + 5){
            spriteRect->y =32;
        }else if (spriteRect->y >32*19 - 5){
            spriteRect->y = 32*17;
        }
        i++;
        if(i==50){
            break;
        }
    }
}
int Point::random_od_0_do_n(int n){
    srand(time(0));
    return rand()%n;
}



