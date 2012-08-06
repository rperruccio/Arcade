#include "Game.h"

Game::Game()
{
    pantalla = NULL;

    running = true;
}

int Game::OnExecute()
{
    if (OnInit() == false)
        return -1;

    SDL_Event e;

    while (running)
    {
        while(SDL_PollEvent(&e))
        {
            OnEvent(&e);
        }

        OnLoop();

        OnRender();
    }

    OnCleanup();

    return 0;
}

int main(int argc, char* argv[])
{
    Game g;

    return g.OnExecute();
}


