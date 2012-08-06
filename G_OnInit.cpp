#include "Game.h"

bool Game::OnInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;

    if ((pantalla = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
        return false;

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_DELAY / 3);

    StateManager::SetActiveState(STATE_INTRO);

    return true;
}
