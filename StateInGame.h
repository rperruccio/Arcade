#ifndef STATEINGAME_H
    #define STATEINGAME_H

#include "State.h"

#include "Area.h"
#include "Camara.h"
#include "Entity.h"
#include "Superficie.h"

#include "Player.h"

#include "Gate.h"

class StateInGame : public State
{
    private:
        StateInGame();
        virtual ~StateInGame();

    private:
        static StateInGame  instance;

        Player              Zero;

    public:
        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

    public:
        void OnActivate();

        void OnDeactivate();

        void OnLoop();

        void OnRender(SDL_Surface* pantalla);

    public:
        static StateInGame* GetInstance();
};

#endif // STATEINGAME_H
