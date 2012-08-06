#include "Game.h"

void Game::OnEvent(SDL_Event* event)
{
    Event::OnEvent(event);

    StateManager::OnEvent(event);
}

void Game::OnExit()
{
    running = false;
}
