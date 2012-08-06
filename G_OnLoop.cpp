#include "Game.h"

void Game::OnLoop()
{
    StateManager::OnLoop();

    CFPS::fpsControl.OnLoop();

    char Buffer[255];
    sprintf(Buffer, "FPS: %d", CFPS::fpsControl.GetFPS());
    SDL_WM_SetCaption(Buffer, Buffer);

}
