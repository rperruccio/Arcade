#include "StateInGame.h"

void StateInGame::OnRender(SDL_Surface* pantalla)
{
    SDL_Rect r;
    r.x = 0;
    r.y = 0;
    r.w = WWIDTH;
    r.h = WHEIGHT;

    SDL_FillRect(pantalla, &r, 0);

    Area::areaControl.OnRender(pantalla, -Camara::camaraControl.GetX(), -Camara::camaraControl.GetY());

    for (int i = 0; i < Entity::entityList.size(); i++)
    {
        if (!Entity::entityList[i])
            continue;

        Entity::entityList[i]->OnRender(pantalla);
    }

    SDL_Flip(pantalla);
}
