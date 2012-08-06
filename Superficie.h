#ifndef SUPERFICIE_H
    #define SUPERFICIE_H

#include <SDL.h>
#include <SDL_image.h>

class Superficie
{
    public:
        Superficie();

    public:
        static SDL_Surface* OnLoad(char* path);

        static bool OnDraw(SDL_Surface* dest, SDL_Surface* src, int x, int y);

        static bool OnDraw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int x2, int y2, int w, int h);
};

#endif // SUPERFICIE_H
