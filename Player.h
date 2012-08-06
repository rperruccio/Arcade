#ifndef PLAYER_H
    #define PLAYER_H

#include "Character.h"

enum //TIEMPO QUE HAY QUE ESPERAR DESPUES DE USAR UN "PODER"
{
    UNO = 5,
    DOS = 25,
    TRES = 125
};

enum // LOS PODERES
{
    NONE = 0,
    EARTH,
    FIRE,
    WIND,
    WATER,
    COLD
};

class Player : public Character
{
    public:
        Player();
        virtual ~Player();

  public:
        bool OnLoad(char* path, int width, int height, int maxFrames);

        void OnLoop();

        void OnRender(SDL_Surface* pantalla);

        void OnCleanup();

        void OnAnimate();

        bool OnCollision(Entity* e);

    public:
        void    Defender();

    private:
        int     poderUno;
        int     poderDos;
        int     poderTres;

        bool    defendiendo;

};

#endif // PLAYER_H
