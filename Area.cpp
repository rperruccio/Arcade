#include "Area.h"

Area Area::areaControl;

Area::Area()
{
    tileSet = NULL;
    areaSize = 0;
}

Area::~Area(){}

bool Area::OnLoad(char* path)
{
    mapList.clear();

    FILE* fileHandler = fopen(path, "r");

    if (fileHandler == NULL)
        return false;

    char tileSetFile[255];

    fscanf(fileHandler, "%s\n", tileSetFile);

    if ((tileSet = Superficie::OnLoad(tileSetFile)) == false)
    {
        fclose(fileHandler);
        return false;
    }

    fscanf(fileHandler, "%d\n", &areaSize);

    for (int x = 0; x < areaSize; x++)
    {
        for (int y = 0; y < areaSize; y++)
        {
            char mapPath[255];

            fscanf(fileHandler, "%s ", mapPath);

            Map tempMap;

            if (tempMap.OnLoad(mapPath) == false)
            {
                fclose(fileHandler);
                return false;
            }

            tempMap.tileSet = this->tileSet;

            mapList.push_back(tempMap);
        }

        fscanf(fileHandler, "\n");
    }

    fclose(fileHandler);

    mapWidth = MAP_WIDTH * TILE_SIZE;
    mapHeight = MAP_HEIGHT * TILE_SIZE;

    return true;

}

void Area::OnRender(SDL_Surface* pantalla, int camaraX, int camaraY)
{
    //int mapWidth = MAP_WIDTH * TILE_SIZE;
    //int mapHeight = MAP_HEIGHT * TILE_SIZE;

    int firstID = -camaraX / mapWidth;
        firstID += ((-camaraY / mapHeight) * areaSize);

    for (int i = 0; i < 4; i++)
    {
        int ID = firstID + ((i / 2) * areaSize) + (i % 2);

        if (ID < 0 || ID >= mapList.size())
            continue;

        int X = ((ID % areaSize) * mapWidth) + camaraX;
        int Y = ((ID / areaSize) * mapHeight) + camaraY;

        mapList[ID].OnRender(pantalla, X, Y);
    }

}

void Area::OnCleanup()
{
    if (tileSet)
        SDL_FreeSurface(tileSet);

    mapList.clear();
}

Map* Area::GetMap(int x, int y)
{
    //int mapWidth = TILE_SIZE * MAP_WIDTH;
    //int mapHeight = TILE_SIZE * MAP_HEIGHT;

    int ID = x / mapWidth;
        ID += ((y / mapHeight) * areaSize);

    if (ID < 0 || ID >= mapList.size())
        return NULL;

    return &mapList[ID];
}

Tile* Area::GetTile(int x, int y)
{
    Map* mapita = GetMap(x, y);

    if (mapita == NULL)
        return NULL;

    x = x % mapWidth;
    y = y % mapHeight;

    return mapita->GetTile(x, y);
}
