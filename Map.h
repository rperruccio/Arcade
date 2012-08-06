#ifndef MAP_H
    #define MAP_H

#include <vector>
#include <SDL.h>

#include "Tile.h"
#include "Superficie.h"

class Map
{
    public:
        Map();
        virtual ~Map();

    public:
        SDL_Surface*        tileSet;

    private:
        std::vector<Tile>   tileList;

    public:
        bool OnLoad(char* path);

        void OnRender(SDL_Surface* pantalla, int mapX, int mapY);

    public:
        Tile* GetTile(int x, int y);
};

#endif // MAP_H
