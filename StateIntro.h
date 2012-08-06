#ifndef STATEINTRO_H
    #define STATEINTRO_H

#include "State.h"
#include "Superficie.h"

class StateIntro: public State
{
    private:
        StateIntro();
        virtual ~StateIntro();

    private:
        static StateIntro   instance;

        SDL_Surface*        logo;

        int                 startTime;

    public:
        void OnActivate();

        void OnDeactivate();

        void OnLoop();

        void OnRender(SDL_Surface* pantalla);

    public:
        static StateIntro* GetInstance();
};

#endif // STATEINTRO_H
