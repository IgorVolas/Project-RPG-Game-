#include "player.h"

Player::Player(Sprite *sprite) :Player_Osnova(sprite), KeyboardEventListener() {


}

void Player::listen(SDL_KeyboardEvent &event) {
    if(event.type == SDL_KEYDOWN) {
        if(event.keysym.sym == SDLK_LEFT) {
            sprite->setState(sprite->getState()|Sprite::LEFT);
        } else if(event.keysym.sym == SDLK_RIGHT) {
            sprite->setState(sprite->getState()|Sprite::RIGHT);
        } else if(event.keysym.sym == SDLK_UP) {
            sprite->setState(sprite->getState()|Sprite::UP);
        } else if(event.keysym.sym == SDLK_DOWN) {
            sprite->setState(sprite->getState()|Sprite::DOWN);
        }
    } else if (event.type == SDL_KEYUP) {
        if(event.keysym.sym == SDLK_LEFT) {
            sprite->setState(sprite->getState()&~Sprite::LEFT);
        } else if(event.keysym.sym == SDLK_RIGHT) {
            sprite->setState(sprite->getState()&~Sprite::RIGHT);
        } else if(event.keysym.sym == SDLK_UP) {
            sprite->setState(sprite->getState()&~Sprite::UP);
        } else if(event.keysym.sym == SDLK_DOWN) {
            sprite->setState(sprite->getState()&~Sprite::DOWN);
        }
    }

}
