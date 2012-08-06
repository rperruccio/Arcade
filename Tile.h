#ifndef TILE_H
    #define TILE_H

#include "Define.h"

enum
{
  TYPE_NONE = 0,
  TYPE_NORMAL,
  TYPE_BLOCK
};

class Tile
{
    public:
        Tile();
        virtual ~Tile();

    public:
        int tileID;

        int typeID;
};

#endif // TILE_H
