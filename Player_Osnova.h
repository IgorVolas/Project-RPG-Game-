#ifndef PLAYER_OSNOVA_H_INCLUDED
#define PLAYER_OSNOVA_H_INCLUDED

#include <SDL2/SDL.h>

#include "drawable.h"
#include "movable.h"
#include "keyboardeventlistener.h"
#include "sprite.h"

class Player_Osnova : public Drawable, public Movable {

public:
    Sprite *sprite;

    Player_Osnova(Sprite *sprite);
    virtual void draw(SDL_Renderer *renderer);
    virtual void move();
    virtual void move(int dx, int dy);
    bool provera();
    virtual ~Player_Osnova(){}
};

#endif // PLAYER_OSNOVA_H_INCLUDED
