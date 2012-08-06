#ifndef GATE_H
    #define GATE_H

#include "Entity.h"

enum
{
  HORIZONTAL = 0,
  VERTICAL = 1
};

enum
{
    ARRIBA_IZQUIERDA = 0,
    ABAJO_DERECHA = 1
};

class Gate : public Entity
{
    public:
        Gate();
        virtual ~Gate();

  public:
        bool OnLoad(char* path, int width, int height, int maxFrames);

        void OnLoop();

        void OnRender(SDL_Surface* pantalla);

        void OnCleanup();

        void OnAnimate();

        bool OnCollision(Entity* e);

    private:
        int     hov;
        int     pos;

        Gate*   destino;

    public:
        void    Set(int hov, int pos);

        int     GetHov();

        bool    SetGate(Gate* g);

    public:
        float   DestinoX(Entity* e);
        float   DestinoY(Entity* e);


};

#endif // GATE_H
