#include "Map.h"

Map::Map()
{
    tileSet = NULL;
}

Map::~Map(){}

bool Map::OnLoad(char* path)
{
    tileList.clear();

    FILE* fileHandler = fopen(path, "r");

    if (fileHandler == NULL)
        return false;

    for (int y = 0; y < MAP_HEIGHT; y++)
    {

        for (int x = 0; x < MAP_WIDTH; x++)
        {
            Tile tempTile;

            fscanf(fileHandler, "%d:%d ", &tempTile.tileID, &tempTile.typeID);

            tileList.push_back(tempTile);
        }
        fscanf(fileHandler, "\n");
    }

    fclose(fileHandler);

    return true;
}

void Map::OnRender(SDL_Surface* pantalla, int mapX, int mapY)
{
    if (pantalla == NULL)
        return;

    int tilesetWidth = tileSet->w / TILE_SIZE;
    int tileetHeight = tileSet->h / TILE_SIZE;

    int ID = 0;

    for (int y = 0; y < MAP_HEIGHT; y++)
    {

        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if (tileList[ID].typeID == TYPE_NONE)
            {
                ++ID;
                continue;
            }

            int tX = mapX + (x * TILE_SIZE);
            int tY = mapY + (y * TILE_SIZE);

            int tileSetX = (tileList[ID].tileID % tilesetWidth) * TILE_SIZE;
            int tileSetY = (tileList[ID].tileID / tilesetWidth) * TILE_SIZE;

            Superficie::OnDraw(pantalla, tileSet, tX, tY, tileSetX, tileSetY, TILE_SIZE, TILE_SIZE);

            ++ID;

        }
    }
}

Tile* Map::GetTile(int x, int y)
{
    int ID = 0;

    ID = x / TILE_SIZE;
    ID += (MAP_WIDTH * (y / TILE_SIZE));

    if (ID < 0 || ID >= tileList.size())
        return NULL;

    return &tileList[ID];
}
