#ifndef GAME_H
    #define GAME_H

#include <SDL.h>
#include "Define.h"

#include "StateManager.h"
#include "CFPS.h"

#include "Event.h"
#include "Superficie.h"

class Game : public Event
{
    public:
        Game();

        int OnExecute();

        SDL_Surface*    pantalla;

    public:
        bool OnInit();

        void OnEvent(SDL_Event* e);

        void OnLoop();

        void OnRender();

        void OnCleanup();

        void OnExit();

    private:
        bool running;

};

#endif // GAME_H
