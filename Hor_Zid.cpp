#include "Horizontalni_Zid.h"

Horizontalni_Zid::Horizontalni_Zid(istream &inputStream, Tileset *tileset , int xx , int yy): Zid(inputStream, tileset,  xx , yy) {
}

void Horizontalni_Zid::draw(SDL_Renderer * renderer){
	double x2 = x;
	double y2 = y;
    for(size_t i = 0; i < zid.size(); i++) {
        tileset->drawTile(zid[i], x2, y2, renderer);
        x2 += 32;
    }
}

int Horizontalni_Zid::getX(){
	return x;
}

int Horizontalni_Zid::getY(){
	return y;
}



