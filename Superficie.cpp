#include "Superficie.h"

Superficie::Superficie()
{
    //ctor
}

SDL_Surface* Superficie::OnLoad(char* path)
{
    SDL_Surface* temp = NULL;
    SDL_Surface* ret = NULL;

    if ((temp = IMG_Load(path)) == NULL)
        return NULL;

    ret = SDL_DisplayFormatAlpha(temp);
    temp = NULL;

    return ret;
}

bool Superficie::OnDraw(SDL_Surface* dest, SDL_Surface* src, int x, int y)
{
    if (dest == NULL || src == NULL)
        return false;

    SDL_Rect destR;

    destR.x = x;
    destR.y = y;

    SDL_BlitSurface(src, NULL, dest, &destR);

    return true;
}

bool Superficie::OnDraw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int x2, int y2, int w, int h)
{
    if (dest == NULL || src == NULL)
        return false;

    SDL_Rect destR;
    destR.x = x;
    destR.y = y;

    SDL_Rect srcR;
    srcR.x = x2;
    srcR.y = y2;
    srcR.w = w;
    srcR.h = h;

    SDL_BlitSurface(src, &srcR, dest, &destR);

    return true;
}
