#include <iostream>
#include <fstream>

#include "engine.h"
#include "level.h"
#include "sprite.h"

using namespace std;

int main(int argc, char** argv)
{
    Engine *eng = new Engine("RPG Game");

    eng->addTileset("resources/tilesets/grass_tileset.txt", "default");
    eng->addTileset("resources/tilesets/fence_tileset1.txt", "ograda"); /** Dodavanje novog tileset-a. */

    ifstream levelStream("resources/levels/level1.txt");
    eng->addDrawable(new Level(levelStream, eng->getTileset("default"))); /** Dodavanje novog nivoa. */

    eng->run();
    delete eng;
    return 0;
}
