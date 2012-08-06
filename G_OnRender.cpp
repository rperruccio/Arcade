#include "Game.h"

void Game::OnRender()
{
    StateManager::OnRender(pantalla);

    SDL_Flip(pantalla);
}
