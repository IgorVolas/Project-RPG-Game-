#include "Zid.h"

Zid::Zid(istream &inputStream, Tileset *tileset , int xx , int yy): Drawable() {
    x = xx;
    y = yy;
	this->tileset = tileset;
    int h;
    char s;
    inputStream >> h ;
    for(int i = 0; i < h; i++) {
        inputStream >> s;
        zid.push_back(s);

    }
}


