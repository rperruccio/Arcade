#ifndef AREA_H
    #define AREA_H

#include "Map.h"

class Area
{
    public:
        Area();
        virtual ~Area();

    public:
        std::vector<Map>    mapList;

        static Area         areaControl;

    private:
        int                 areaSize;

        SDL_Surface*        tileSet;

        int                 mapWidth;

        int                 mapHeight;

    public:
        bool OnLoad(char* path);

        void OnRender(SDL_Surface* pantalla, int cameraX, int camaraY);

        void OnCleanup();

    public:
        Map*    GetMap(int X, int Y);

        Tile*   GetTile(int X, int Y);
};

#endif // AREA_H
