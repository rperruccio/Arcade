#include "StateInGame.h"

void StateInGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    switch(sym)
    {
        case SDLK_LEFT:
        {
            Zero.moveLeft = true;
            Zero.dir = IZQUIERDA;
            break;
        }

        case SDLK_RIGHT:
        {
            Zero.moveRight = true;
            Zero.dir = DERECHA;
            break;
        }

        case SDLK_s:
        {
            Zero.Jump();
            break;
        }

        case SDLK_a:
        {
            Zero.Defender();
            break;
        }

        default: {}
    }

    Zero.moving = Zero.moveLeft or Zero.moveRight;
}

void StateInGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    switch(sym)
    {
        case SDLK_LEFT:
        {
            Zero.moveLeft = false;
            break;
        }

        case SDLK_RIGHT:
        {
            Zero.moveRight = false;
            break;
        }

        case SDLK_a:
        {
            Zero.Defender();
            break;
        }

        default: {}
    }

    Zero.moving = Zero.moveLeft or Zero.moveRight;
}
