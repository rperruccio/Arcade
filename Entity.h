#ifndef ENTITY_H
    #define ENTITY_H

#include <vector>

#include "Animation.h"
#include "Superficie.h"
#include "Area.h"
#include "Camara.h"
#include "CFPS.h"

enum
{
    ENTITY_TYPE_GENERIC = 0,
    ENTITY_TYPE_PLAYER,
    ENTITY_TYPE_BADGUY
};

enum
{
    ENTITY_FLAG_NONE = 0,
    ENTITY_FLAG_GRAVITY = 0x00000001,
    ENTITY_FLAG_GHOST   = 0x00000002,
    ENTITY_FLAG_MAPONLY = 0x00000004
};

enum
{
    IZQUIERDA = 0,
    DERECHA
};

class Entity
{
    public:
        Entity();
        virtual ~Entity();

    public:
        static std::vector<Entity*> entityList;

    protected:
        Animation                   animControl;

        SDL_Surface*                imagen;

    public:
        float                       x;
        float                       y;

        int                         height;
        int                         width;

        bool                        moveLeft;
        bool                        moveRight;

    public:
        int                         dir;

        bool                        moving;

    public:
        int                         type;

        bool                        dead;
        int                         flags;

    public:
        float                       maxSpeedX;
        float                       maxSpeedY;

    protected:
        float                       speedX;
        float                       speedY;

        float                       accelX;
        float                       accelY;

    protected:
        float                       colFrame;
        float                       filaFrame;

    protected:
        int                         colX;
        int                         colY;
        int                         colWidth;
        int                         colHeight;

    protected:
        bool                        canJump;

    public:
        virtual bool OnLoad(char* path, int width, int height, int maxFrames);

        virtual void OnLoop();

        virtual void OnRender(SDL_Surface* pantalla);

        virtual void OnCleanup();

        virtual void OnAnimate();

        virtual bool OnCollision(Entity* e);

    public:
        void OnMove(float moveX, float moveY);

        void StopMove();

        void SetColFrame(int f);

        bool Jump();


        void SetPos(float x, float y);

    public:
        bool Choca(int oX, int oY, int oW, int oH);

    private:
        bool PosValid(int X, int Y);

        bool PosValidTile(Tile* t);

        bool PosValidEntity(Entity* e, int X, int Y);
};

class EntityCol
{
    public:
        static std::vector<EntityCol>   entityColList;

    public:
        Entity*                      entidadA;
        Entity*                      entidadB;

    public:
        EntityCol();
};

#endif // ENTITY_H
