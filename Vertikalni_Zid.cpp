#include "Vertikalni_Zid.h"

Vertikalni_Zid::Vertikalni_Zid(istream &inputStream, Tileset *tileset , int xx , int yy): Zid(inputStream, tileset,  xx , yy) {
}

void Vertikalni_Zid::draw(SDL_Renderer * renderer){
	double x2 = x;
	double y2 = y;
    for(size_t i = 0; i < zid.size(); i++) {
        tileset->drawTile(zid[i], x2, y2, renderer);
        y2 += 32;
    }
}

int Vertikalni_Zid::getX(){
	return x;
}

int Vertikalni_Zid::getY(){
	return y;
}
