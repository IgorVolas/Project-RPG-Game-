#ifndef ZID_H_INCLUDED
#define ZID_H_INCLUDED

#include <iostream>
#include <vector>

#include "drawable.h"
#include "tileset.h"

using namespace std;

class Zid : public Drawable {
protected:
	Tileset* tileset;
    vector<char > zid;
    int x,y;

public:

	Zid(istream &inputStream, Tileset *tileset , int xx , int yy);
};
#endif // ZID_H_INCLUDED
