#ifndef STATE_H
    #define STATE_H

#include "Event.h"

class State : public Event
{
    public:
        State();
        virtual ~State();

    public:
        virtual void OnActivate() = 0;

        virtual void OnDeactivate() = 0;

        virtual void OnLoop() = 0;

        virtual void OnRender(SDL_Surface* pantalla) = 0;

};

#endif // STATE_H
