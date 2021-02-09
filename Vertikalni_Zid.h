#ifndef VERTIKALNI_ZID_H_INCLUDED
#define VERTIKALNI_ZID_H_INCLUDED

#include <iostream>
#include "tileset.h"

#include "Zid.h"

using namespace std;

class Vertikalni_Zid : public Zid {
public:
	Vertikalni_Zid(istream &inputStream, Tileset *tileset ,int xx , int yy);
	virtual void draw(SDL_Renderer * renderer);
	int getX();
	int getY();
	virtual ~Vertikalni_Zid(){}
};

#endif // VERTIKALNI_ZID_H_INCLUDED
