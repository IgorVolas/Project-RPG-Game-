#include "engine.h"

ostream& operator<<(ostream& out, const Level& l) {
    int rows = l.getLevelMatrix().size();
    int cols = 0;
    if(rows > 0) {
        cols = l.getLevelMatrix()[0].size();
    }
    out << rows << " " << cols << endl;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            out << l.getLevelMatrix()[i][j] << " ";
        }
        out << endl;
    }

    return out;
}

Engine::Engine(string title) {
    nivo=1;
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

     ifstream fajl("highest_score.txt");
     fajl >> highest_score;

}

void Engine::addTileset(Tileset *tileset, const string &name) {
    tilesets[name] = tileset;
}

void Engine::addTileset(istream &inputStream, const string &name) {
    addTileset(new Tileset(inputStream, renderer), name);
}

void Engine::addTileset(const string &path, const string &name) {
    ifstream tilesetStream(path);

    addTileset(tilesetStream, name);
}

Tileset* Engine::getTileset(const string &name) {
    return tilesets[name];
}

void Engine::addDrawable(Drawable *drawable) {
    drawables.push_back(drawable);
}

void Engine::run() {
    int maxDelay = 1000/frameCap;
    int frameStart = 0;
    int frameEnd = 0;

    bool running = true;
    SDL_Event event;

    cout << (*dynamic_cast<Level*>(drawables[0])) << endl;

    ifstream PlantSheeta("resources/creatures/plants_sprite_sheet.txt");
    SpriteSheet *PlantSheet = new SpriteSheet(PlantSheeta, renderer);

    ifstream MeatSheeta("resources/creatures/meat.txt");
    SpriteSheet *MeatSheet = new SpriteSheet(MeatSheeta, renderer);

    ifstream BagSheeta("resources/creatures/fish_spritesheet.txt");
    SpriteSheet *BagSheet = new SpriteSheet(BagSheeta, renderer);


    Point *pt=new Point(PlantSheet);
    drawables.push_back(pt);
    Point *pt1=new Point(MeatSheet , 2,32,32);// poenima je dodeljena vrednost spritesheet sirina visina
    drawables.push_back(pt1);
    Point *pt2=new Point(BagSheet , 3,32,32);
    drawables.push_back(pt2);                 // svi pointi su dodati u drawables da bi mogla biti pozvana redefinisana metoda draw




    ifstream spriteSheetStream("resources/creatures/sprite_sheet.txt");
    SpriteSheet *sheet = new SpriteSheet(spriteSheetStream, renderer);


    Sprite *sp = new Sprite(sheet);
    sp->setFrameSkip(4);

    Player *player = new Player(sp);

    drawables.push_back(player);
    movables.push_back(player);
    eventListeners.push_back(player);



    ifstream dogsheet("resources/creatures/pas.txt");
    SpriteSheet *dog_sheet = new SpriteSheet(dogsheet, renderer);
    Sprite *dog_pas = new Sprite(dog_sheet);
    dog_pas->setFrameSkip(2);
    Friend *friendi_ =  new Friend(dog_pas);
    friendi_->looking_for_point(pt,pt1,pt2);
    movables.push_back(friendi_);
    drawables.push_back(friendi_);


    ifstream VLevoStream("resources/Zid/VertikalniLEVO.txt");
    Vertikalni_Zid* zidLevo = new Vertikalni_Zid(VLevoStream, this->getTileset("ograda") , 0 , 0);
    drawables.push_back(zidLevo);

    ifstream VDesnoStream("resources/Zid/VertikalniDESNO.txt");
    Vertikalni_Zid* zidDesno = new Vertikalni_Zid(VDesnoStream, this->getTileset("ograda") , 9*32 , 0);     // napravljeni zidovi
    drawables.push_back(zidDesno);

    ifstream HGoreStream("resources/Zid/HorizontalniGORE.txt");
    Horizontalni_Zid* HGore = new Horizontalni_Zid(HGoreStream , this->getTileset("ograda") , 0 , 0);
    drawables.push_back(HGore);

    ifstream HDoleStream("resources/Zid/HorizontalniDOLE.txt");
    Horizontalni_Zid* HDole= new Horizontalni_Zid(HDoleStream , this->getTileset("ograda") , 0 , 19*32);
    drawables.push_back(HDole);

    while(running) {
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            } else {
                for(size_t i = 0; i < eventListeners.size(); i++) {
                    eventListeners[i]->listen(event);
                }
            }
        }

        for(size_t i = 0; i < movables.size(); i++) {
            movables[i]->move();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        for(size_t i = 0; i < drawables.size(); i++) {
            drawables[i]->draw(renderer);
        }

        drawScore(pt->pokupio(player),renderer,1);
        friendi_->trazi_point();

        pt->razmesti(pt1);
        pt->razmesti(pt2);
        pt1->razmesti(pt2);

        pt->pokupio(player);
        pt1->pokupio(player);
        pt2->pokupio(player);
        pt->pokupio(friendi_);
        pt1->pokupio(friendi_);
        pt2->pokupio(friendi_);


        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay) {
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
    delete PlantSheet;
    delete MeatSheet;
    delete BagSheet;
    delete pt;
    delete pt1;
    delete pt2;
    delete sheet;
    delete sp;
    delete player;
    delete dog_sheet;
    delete dog_pas;
    delete friendi_;
    delete zidDesno;
    delete zidLevo;
    delete HGore;
    delete HDole;
}



int Engine::drawScore(int rezultat, SDL_Renderer* renderer,int max){
    TTF_Font* font = TTF_OpenFont("font/comicbd.ttf", 24);
    SDL_Color white = {0, 0, 255};
    stringstream ss;
    ss << "Poeni " << rezultat ;
    stringstream ss1;
    ss1<< "HIGH SCORE: " <<highest_score;
    SDL_Surface* text_surface = TTF_RenderText_Solid(font,ss.str().c_str(), white);
    SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_Rect text_rect;
    text_rect.x = 32*10;
    text_rect.y = 0;
    text_rect.w =text_surface->w;
    text_rect.h =text_surface->h;

    SDL_RenderCopy(renderer, text, NULL, &text_rect);

    SDL_Surface* text_surface1 = TTF_RenderText_Solid(font,ss1.str().c_str(), white);
    SDL_Texture* text1 = SDL_CreateTextureFromSurface(renderer, text_surface1);
    SDL_Rect text_rect1;
    text_rect1.x = 32*10;
    text_rect1.y = 32;
    text_rect1.w =text_surface1->w;
    text_rect1.h =text_surface1->h;

     SDL_RenderCopy(renderer, text1, NULL, &text_rect1);

    if(rezultat > highest_score){
        highest_score = rezultat;
    }
    return rezultat;
}

Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    ofstream myfile;
    myfile.open("highest_score.txt");
    myfile << highest_score;
    myfile.close();
}
