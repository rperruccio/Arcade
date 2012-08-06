#ifndef STATEMANAGER_H
    #define STATEMANAGER_H

#include "State.h"

enum
{
    STATE_NONE,
    STATE_INTRO,
    STATE_GAME,
    STATE_LOADING,
    STATE_MENU
};

class StateManager
{
    public:
        StateManager();
        virtual ~StateManager();

    private:
        static State*   activeState;

    public:
        static void OnEvent(SDL_Event* e);

        static void OnLoop();

        static void OnRender(SDL_Surface* pantalla);

    public:
        static void SetActiveState(int StateID);

        static State* GetActiveState();
};

#endif // STATEMANAGER_H
