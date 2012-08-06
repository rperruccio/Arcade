#ifndef CHARACTER_H
    #define CHARACTER_H

#include "Entity.h"

enum  //SOLO PARA CHARACTERS
{
    ACCION_PARADO = 0,
    ACCION_CAMINANDO = 2,
    ACCION_CORRIENDO = 4,
    ACCION_SALTANDO = 6
};

class Character : public Entity
{
    public:
        Character();
        virtual ~Character();

    public:
        virtual bool OnLoad(char* path, int width, int height, int maxFrames);

        virtual void OnLoop();

        virtual void OnRender(SDL_Surface* pantalla);

        virtual void OnCleanup();

        virtual void OnAnimate();

        virtual bool OnCollision(Entity* e);

    protected:
        int     accion;

};

#endif // CHARACTER_H
