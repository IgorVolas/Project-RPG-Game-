#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL2/SDL.h>
#include "Player_Osnova.h"
#include "drawable.h"
#include "movable.h"
#include "keyboardeventlistener.h"
#include "sprite.h"

class Player : public Player_Osnova, public KeyboardEventListener {

public:
    Player(Sprite *sprite);

    virtual void listen(SDL_KeyboardEvent &event);

};

#endif // PLAYER_H_INCLUDED
