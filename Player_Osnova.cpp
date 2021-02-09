#include "Player_Osnova.h"

Player_Osnova::Player_Osnova(Sprite *sprite) : Drawable(), Movable() {
    this->sprite = sprite;

}

void Player_Osnova::draw(SDL_Renderer *renderer) {
    sprite->draw(renderer);
}

void Player_Osnova::move() {
    if(provera()){
        sprite->move();
    }
}
bool Player_Osnova::provera(){
    int xx = this->sprite->spriteRect->x;
    int yy = this->sprite->spriteRect->y;

        if(xx - 1 <= 0){
            this->sprite->spriteRect->x++;
            return 0;
        }


        if(xx + 1 >= 8*32){
            this->sprite->spriteRect->x--;
            return 0;
        }
        if(yy - 1 <= 0){
            this->sprite->spriteRect->y++;
            return 0;
        }

        if(yy + 1 >= 18*32){
            this->sprite->spriteRect->y--;
            return 0;
        }

    return 1;
}

void Player_Osnova::move(int dx, int dy) {
    sprite->move(dx, dy);
}


