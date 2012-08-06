#include "StateManager.h"

#include "StateIntro.h"
#include "StateInGame.h"

State* StateManager::activeState = 0;

StateManager::StateManager()
{
    //ctor
}

StateManager::~StateManager(){}


void StateManager::OnEvent(SDL_Event* e)
{
    if (activeState)
        activeState -> OnEvent(e);
}

void StateManager::OnLoop()
{
    if (activeState)
        activeState -> OnLoop();
}

void StateManager::OnRender(SDL_Surface* pantalla)
{
    if (activeState)
        activeState -> OnRender(pantalla);
}

void StateManager::SetActiveState(int stateID)
{
    if (activeState)
        activeState -> OnDeactivate();

    if (stateID == STATE_NONE)  activeState = 0;
    if (stateID == STATE_INTRO) activeState = StateIntro::GetInstance();
    if (stateID == STATE_GAME)  activeState = StateInGame::GetInstance();

    if (activeState)
        activeState -> OnActivate();
}

State* StateManager::GetActiveState()
{
    return activeState;
}


