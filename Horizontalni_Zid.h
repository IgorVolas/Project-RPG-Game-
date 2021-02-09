#ifndef HORIZONTALNI_ZID_H_INCLUDED
#define HORIZONTALNI_ZID_H_INCLUDED

#include <iostream>
#include "tileset.h"

#include "Zid.h"

using namespace std;

class Horizontalni_Zid : public Zid {
public:
	Horizontalni_Zid(istream &inputStream, Tileset *tileset ,int xx , int yy);
	virtual void draw(SDL_Renderer * renderer);
	int getX();
	int getY();
	virtual ~Horizontalni_Zid(){}
};

#endif // HORIZONTALNI_ZID_H_INCLUDED
