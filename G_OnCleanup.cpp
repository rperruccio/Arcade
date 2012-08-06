#include "Game.h"

void Game::OnCleanup()
{
    StateManager::SetActiveState(STATE_NONE);

    if (pantalla)
        SDL_FreeSurface(pantalla);

    SDL_Quit();
}
