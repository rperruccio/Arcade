#include "StateIntro.h"

#include "StateManager.h"

StateIntro StateIntro::instance;

StateIntro::StateIntro()
{
    logo = NULL;
    startTime = 0;
}

StateIntro::~StateIntro(){}

void StateIntro::OnActivate()
{
    logo = Superficie::OnLoad("./Imagenes/splash.jpg");

    startTime = SDL_GetTicks();
}

void StateIntro::OnDeactivate()
{
    if (logo)
    {
        SDL_FreeSurface(logo);
        logo = NULL;
    }
}

void StateIntro::OnLoop()
{
    if (startTime + 3000 < SDL_GetTicks())
        StateManager::SetActiveState(STATE_GAME);
}

void StateIntro::OnRender(SDL_Surface* pantalla)
{
    if (logo != NULL && pantalla != NULL)
            Superficie::OnDraw(pantalla, logo, 0, 0);
}

StateIntro* StateIntro::GetInstance()
{
    return &instance;
}

